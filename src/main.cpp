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
 * @package  Main
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @license  Affero General Public License
 * @link     http://tatoeba.org
 */


#include <iostream>


#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppdb/frontend.h>
#include <cppcms/json.h>

#include "tatoeba.h"

#include "contents/Config.h"
#include "generics/Languages.h"
#include "generics/ActionId.h"


#include "models/TatoDB.h"
//#include "models/SearchEngine.h"
using namespace std;
using namespace cppcms;

int main(int argc,char ** argv)
{
    //TODO send notice message to logs instead of cout

    service app(argc, argv);
    /*load some conf defined variables*/
    Config *conf = Config::get_instance();
    conf->cssPath = app.settings().get<string>("tatoeba.css");
    conf->imgPath = app.settings().get<string>("tatoeba.img");
    conf->webPath = app.settings().get<string>("tatoeba.web");
    conf->indexesPath = app.settings().get<string>(
        "tatoeba.searchEngine.indexesPath"
    );
    conf->sqlite3Path = app.settings().get<string>(
        "tatoeba.sqlite3.path"
    );
        

    /*start the graph database*/
    string dictPath = app.settings().get<string>("tatoeba.tatodbxml");
    TatoDB::get_instance(dictPath);
    cout << "[NOTICE] database loaded" << endl;

    /*load the languages*/
    Languages::get_instance();
    Languages::get_instance()->init(
        app.settings().at("tatoeba.languages").object()
    );

    //singletons::ActionId::get_instance();
    /*instantiate the website application*/
    cout << "[NOTICE] website to be launched" << endl;
    booster::intrusive_ptr<apps::Tatoeba> tatoApp = new apps::Tatoeba(app);
    app.applications_pool().mount(tatoApp);
    /*launch it */
    cout << "[NOTICE] website launched" << endl;
    app.run();
    cout << "[NOTICE] website stopped" << endl;
    cout << "[NOTICE] going to dump the database" << endl;
    TatoDB::get_instance("")->dump("dump.xml");

    /*time to destroy all the singletons*/
    singletons::ActionId::kill();
    //SearchEngine::kill();
    TatoDB::kill();
    Config::kill();
    Languages::kill();
}

