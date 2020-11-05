#include <set>
#include <string>

using namespace std;

class ActionNames {
    public:
        const name ACCOUNTS_ADD = name("addaccount");
        const name ACCOUNTS_REMOVE = name("deleteaccnt");
        const name ACCOUNTS_EDIT = name("editaccount");
        const name TRANSACTIONS_ADD = name("transact");
        const name TRANSACTIONS_REMOVE = name("deletetrxn");
        const name TRANSACTIONS_EDIT = name("edittrxn");
        const name PROJECTS_REMOVE = name("nothing");
        const name PROJECTS_EDIT = name("nothing2");
        const name PERMISSIONS_ADD_PERMISSION = name("givepermissn");
        const name PERMISSIONS_REMOVE_PERMISSION = name("removeprmssn");
        const name PERMISSIONS_ADD_ROLE = name("addrole");
        const name PERMISSIONS_REMOVE_ROLE = name("removerole");
        const name PERMISSIONS_ASSIGN = name("assignrole");

        ActionNames () {
            constants.insert(ACCOUNTS_ADD);
            constants.insert(ACCOUNTS_REMOVE);
            constants.insert(ACCOUNTS_EDIT);
            constants.insert(TRANSACTIONS_ADD);
            constants.insert(TRANSACTIONS_REMOVE);
            constants.insert(TRANSACTIONS_EDIT);
            constants.insert(PERMISSIONS_ADD_PERMISSION);
            constants.insert(PERMISSIONS_REMOVE_PERMISSION);
            constants.insert(PERMISSIONS_ADD_ROLE);
            constants.insert(PERMISSIONS_REMOVE_ROLE);
            constants.insert(PERMISSIONS_ASSIGN);
        }

        bool is_valid_constant (name constant) {
            auto itr = constants.find(constant);
            return (itr != constants.end()) ? true : false;
        }
    private:
        set<name> constants;
} ACTION_NAMES;
