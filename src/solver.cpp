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


bool dfsIDA(Cube cube,
            int depth,
            int maxDepth,
            string path,
            string &answer)
{
    if(cube.isSolved())
    {
        answer = path;
        return true;
    }

    if(depth == maxDepth)
        return false;

    string moves[]={"R","R'","U","U'"};

    for(string m : moves)
    {
        Cube next=cube;
        next.applyMove(m);

        if(dfsIDA(next,
                  depth+1,
                  maxDepth,
                  path+" "+m,
                  answer))
            return true;
    }

    return false;
}


string Solver::idaSolve(Cube start)
{
    for(int depth=0; depth<=10; depth++)
    {
        string answer="";

        if(dfsIDA(start,0,depth,"",answer))
            return answer;
    }

    return "No solution";
}