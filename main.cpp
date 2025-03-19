/*#include <iostream>
#include "Graph.h"
#include "MapSearch.h"
#include "stlastar.h"

int main() {
    // Crea una mappa (griglia) 10x10
    Graph graph(10, 10);

    // Definisce lo stato iniziale e quello obiettivo
    MapSearch start(0, 0, &graph);
    MapSearch goal(9, 9, &graph);

    // Crea l'istanza dell'algoritmo A* (definito in stlastar.h)
    AStarSearch<MapSearch> astarsearch;    //FIXME: stlastar changed into AStarSearch
    astarsearch.SetStartAndGoalStates(start, goal);

    // Esegue la ricerca a passi
    unsigned int searchState;
    do {
        searchState = astarsearch.SearchStep();
    } while(searchState == AStarSearch<MapSearch>::SEARCH_STATE_SEARCHING); //FIXME: stlastar changed into AStarSearch

    // Se il percorso è stato trovato, lo stampa a video
    if (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SUCCEEDED) {
        std::cout << "Percorso trovato:" << std::endl;
        MapSearch *node = nullptr;
        // L'algoritmo restituisce il percorso dal goal allo start
        while ((node = astarsearch.GetSolutionNext()) != nullptr) {
            node->PrintNodeInfo();
        }
    } else {
        std::cout << "Percorso non trovato!" << std::endl;
    }

    // Libera la memoria allocata per i nodi del percorso soluzione
    astarsearch.FreeSolutionNodes();

    return 0;
}
*/
#include <iostream>
#include "Graph.h"
#include "MapSearch.h"  // Questo header definisce la classe MapSearchNode
#include "stlastar.h"
#include "Character.h"
#include "Game.h"




int main() {
    //init Game engine
    Game game;

    //GAME LOOP
    while(game.windowIsOpen()) {
        //FRAME
        //1. event polling


        //2. update the game
        game.update(); //event polling is in update

        //3. render the game
        game.render();

    }

    //end of application





    return 0;


    /*
    // Crea una mappa (griglia) 10x10
    Graph graph(10, 10);

    // Definisce lo stato iniziale e quello obiettivo usando MapSearchNode
    MapSearch start(0, 0, &graph);
    MapSearch goal(9, 9, &graph);

    // Crea l'istanza dell'algoritmo A*
    AStarSearch<MapSearch> astarsearch;
    astarsearch.SetStartAndGoalStates(start, goal);

    // Esegue la ricerca a passi
    unsigned int searchState;
    do {
        searchState = astarsearch.SearchStep();
    } while (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SEARCHING);

    // Se il percorso è stato trovato, lo stampa a video
    if (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SUCCEEDED) {
        std::cout << "Percorso trovato:" << std::endl;
        MapSearch *node = nullptr;
        // L'algoritmo restituisce i nodi della soluzione, uno alla volta, dal goal allo start
        while ((node = astarsearch.GetSolutionNext()) != nullptr) {
            node->PrintNodeInfo();
        }
    } else {
        std::cout << "Percorso non trovato!" << std::endl;
    }

    // Libera la memoria allocata per i nodi della soluzione
    astarsearch.FreeSolutionNodes();

    Character bob("bob rob");
    bob.move(2,3, &graph);
*/

}



/*MAIN DA FINDPATH.CPP
 *

int main( int argc, char *argv[] )
{

    cout << "STL A* Search implementation\n(C)2001 Justin Heyes-Jones\n";

    // Our sample problem defines the world as a 2d array representing a terrain
    // Each element contains an integer from 0 to 5 which indicates the cost
    // of travel across the terrain. Zero means the least possible difficulty
    // in travelling (think ice rink if you can skate) whilst 5 represents the
    // most difficult. 9 indicates that we cannot pass.

    // Create an instance of the search class...

    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount = 0;

    const unsigned int NumSearches = 1;

    while(SearchCount < NumSearches)
    {

        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = rand()%MAP_WIDTH;
        nodeStart.y = rand()%MAP_HEIGHT;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = rand()%MAP_WIDTH;
        nodeEnd.y = rand()%MAP_HEIGHT;

        // Set Start and goal states

        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {
            SearchState = astarsearch.SearchStep();

            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

			int len = 0;

			cout << "Open:\n";
			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();

			}

			cout << "Open list has " << len << " nodes\n";

			len = 0;

			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				p->PrintNodeInfo();
	#endif
				p = astarsearch.GetClosedListNext();
			}

			cout << "Closed list has " << len << " nodes\n";
#endif

        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
        {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;

            node->PrintNodeInfo();
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();

                if( !node )
                {
                    break;
                }

                node->PrintNodeInfo();
                steps ++;

            };

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();


        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";

        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount ++;

        astarsearch.EnsureMemoryFreed();
    }

    return 0;
}
*/