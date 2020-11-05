const assert = require('assert');
const accounts = require('../scripts/accounts.json')
const { names } = require('../scripts/helper')

function getError (err) {
    return JSON.parse(err).error.details[0].message.replace('assertion failure with message: ', '')
}


describe("Projects Contract", function (eoslime) {

    let firstuser = eoslime.Account.load(names.firstuser, accounts[names.firstuser].privateKey, 'active')
    let seconduser = eoslime.Account.load(names.seconduser, accounts[names.seconduser].privateKey, 'active')
    let thirduser = eoslime.Account.load(names.thirduser, accounts[names.thirduser].privateKey, 'active')
    let projects = eoslime.Account.load(names.projects, accounts[names.projects].privateKey, 'active')
    let accountss = eoslime.Account.load(names.accounts, accounts[names.accounts].privateKey, 'active')
    let permissions = eoslime.Account.load(names.permissions, accounts[names.permissions].privateKey, 'active')

    let projectsContract
    let firstuserContract
    let seconduserContract
    let thirduserContract
    let accountssContract
    let permissionsContract

    before(async () => {

        projectsContract = await eoslime.Contract.at(names.projects, projects)
        firstuserContract = await eoslime.Contract.at(names.projects, firstuser)
        seconduserContract = await eoslime.Contract.at(names.projects, seconduser)
        thirduserContract = await eoslime.Contract.at(names.projects, thirduser)
        accountssContract = await eoslime.Contract.at(names.accounts, accountss)
        permissionsContract = await eoslime.Contract.at(names.permissions, permissions)

        console.log('reset permissions contract')
        await permissionsContract.reset()

        console.log('reset projects contract')
        await projectsContract.reset()

        console.log('reset accounts contract')
        await accountssContract.reset()

    })
})


