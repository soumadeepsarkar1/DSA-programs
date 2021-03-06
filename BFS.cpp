//https://www.hackerrank.com/challenges/bfsshortreach/problem?h_r=internal-search
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    //first construct an adjacency list, vertices are from 1 to n
    vector<vector<int>> adj(n);
    int i;
    for(i=0;i<m;i++)
    {
        adj[edges[i][0]-1].push_back(edges[i][1]);
        adj[edges[i][1]-1].push_back(edges[i][0]);
    }
    queue<int> q;
    vector<bool> visited(n,0);
    vector<int> dist(n,-1);
    dist[s-1]=0;
    q.push(s);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i:adj[f-1])
        {
            if(visited[i-1]==0)
            {
                q.push(i);
                visited[i-1]=1;
                dist[i-1]=dist[f-1]+6;
            }
        }
    }
    //deleting the distance for the start node from dist
    for(i=s-1;i<n-1;i++)
        dist[i]=dist[i+1];
    dist.pop_back();
    return(dist);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
