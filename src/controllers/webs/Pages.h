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

#ifndef CONTROLLERS_WEBS_PAGES_H
#define CONTROLLERS_WEBS_PAGES_H

#include "Controller.h"

namespace controllers {
namespace webs { 
/**
 * @class Pages
 * contains all functions to generate all independant pages
 */
class Pages : public Controller {
    public:
        /**
         * Constructor
         */
        Pages(cppcms::service &serv);
        /**
         * generate home page
         */
        void homepage();
        /**
         * Main page to add sentences and so
         */
        void contribute();
        /**
         * Terms of use page
         */
        void terms_of_use();
        /**
         * Team and Credits page
         */
        void team_and_credits();
        //TODO doc

        /**
         * @brief Display nothing, only to treat the form which permit
         *        to change the language of the user interface
         * @since 2 September 2011
         */
        void change_interface_lang_treat();
};

} // End namespace webs
} // End namespace generics

#endif
