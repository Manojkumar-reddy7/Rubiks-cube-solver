#include "../include/solver.h"
#include <queue>
#include <unordered_set>

string Solver::bfsSolve(Cube start) {

    queue<pair<Cube,string>> q;
    unordered_set<string> visited;

    q.push({start,""});
    visited.insert(start.getState());

    string moves[] = {"R","R'","U","U'"};

    while(!q.empty()) {

        Cube current = q.front().first;
        string path = q.front().second;
        q.pop();

        if(current.isSolved())
            return path;

        string lastMove = "";

        if(!path.empty()) {
            int pos = path.find_last_of(' ');
            lastMove = path.substr(pos + 1);
        }

        for(string move : moves) {

            if((lastMove=="R" && move=="R'") ||
               (lastMove=="R'" && move=="R") ||
               (lastMove=="U" && move=="U'") ||
               (lastMove=="U'" && move=="U"))
                continue;

            Cube next = current;
            next.applyMove(move);

            string state = next.getState();

            if(visited.count(state))
                continue;

            visited.insert(state);

            q.push({next, path + " " + move});
        }
    }

    return "No solution";
}