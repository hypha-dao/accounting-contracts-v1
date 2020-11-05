#pragma once

#include <eosio/eosio.hpp>
#include <eosio/system.hpp>
#include <eosio/asset.hpp>
#include <eosio/symbol.hpp>
#include <common.hpp>
#include <account_types.hpp>
#include <account_subtypes.hpp>
#include <project_status.hpp>
#include <user_types.hpp>
#include <investment_status.hpp>

using namespace eosio;
using namespace std;

CONTRACT projects : public contract {

    public:

        using contract::contract;
        projects(name receiver, name code, datastream<const char*> ds)
            : contract(receiver, code, ds),
              projects_table(receiver, receiver.value),
              users(receiver, receiver.value)
              {}

        ACTION reset ();

        ACTION addtestuser (name user, string user_name, string type);

    private:

        TABLE project_table {
			uint64_t project_id;
			name owner; // who is a project owner?
            string project_name;
			string description;
            uint64_t created_date;
            string status;

			uint64_t primary_key() const { return project_id; }
		};

        TABLE user_table {
            name account;
            string user_name;
            uint64_t entity_id;
            string type;

            uint64_t primary_key() const { return account.value; }
        };

        typedef eosio::multi_index <name("projects"), project_table> project_tables;

        typedef eosio::multi_index <name("users"), user_table> user_tables;

        project_tables projects_table;
        user_tables users;

        void checkusrtype (name user, string type);

};


// users:
// account
// name
// entity_id
// type (investor, developer, fund)


// investors
// id
// 


// devepoler:
// id
// name


// investments:
// user
// project_id
// file
// status (pendding, funding, funded)
// approved_by
// approved_date
// investment_date


// fund_transfers
// file
// amount
// investment_id
// user
// timestamp


// actions:
//  addproject
//  invest
//  make_investment_transfer
//  approve_investment
//  approve_project
