#include <projects.hpp>

void projects::checkusrtype (name user, string type) {
	auto itr_user = users.find(user.value);
	check(itr_user != users.end(), contract_names::projects.to_string() + ": the user does not exist.");
	check(itr_user -> type == type, contract_names::projects.to_string() + ": the user type must be " + type + " to do this.");
}

ACTION projects::reset () {
    require_auth(_self);

    auto itr_p = projects_table.begin();
	while (itr_p != projects_table.end()) {
		itr_p = projects_table.erase(itr_p);
	}

	auto itr_users = users.begin();
	while (itr_users != users.end()) {
		itr_users = users.erase(itr_users);
	}
}

ACTION projects::addtestuser (name user, string user_name, string type) {
	uint64_t entity_id = 0;

	users.emplace(_self, [&](auto & new_user){
		new_user.account = user;
		new_user.user_name = user_name;
		new_user.type = type;
		new_user.entity_id = entity_id;
	});
}

EOSIO_DISPATCH(projects, (reset)(addtestuser));




