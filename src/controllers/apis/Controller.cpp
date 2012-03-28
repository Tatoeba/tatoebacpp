/**
 * Tatoeba Project, free collaborative creation of multilingual corpuses project
 * Copyright (C) 2011 Allan SIMON <allan.simon@supinfo.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * @category Tatoebacpp
 * @package  Controllers
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @license  Affero General Public License
 * @link     http://tatoeba.org
 */


#include "Controller.h"
#include <cppcms/session_interface.h>
#include <cppcms/filters.h>

#include "contents/content.h"

namespace controllers {
namespace apis {

/**
 *
 */
Controller::Controller(cppcms::service &serv) : 
    controllers::generics::Controller(serv)
{


}

/**
 *
 */
void Controller::init_content(contents::BaseContent& content) {
    
    response().content_encoding("UTF-8");
    response().set_content_header("text/xml; charset=UTF-8");

}



/**
 *
 */
inline bool Controller::is_logged() {
    //TODO for API replace maybe by api_key ?
    return !session()["name"].empty();
}



/**
 *
 */
bool Controller::check_permission() {

    //TODO for the moment we do not handle case
    // when you're logged but you're current group has not
    // enough priviledges

    //TODO
    if (!is_logged()) {
        // TODO maybe add a error message?
        return false;
    }
    return true;
}

/**
 *
 */
int Controller::get_current_user_id() {
    // TODO maybe replace by get api key?
    // NOTE: actually in case of an application where the user can login
    // with his username but will also send an API key 
    //std::cout << "[NOTICE] current id:" << session()["userId"] << std::endl;
    return atoi(session()["userId"].c_str());
}


} // End namespace generics
} // End namespace controllers

