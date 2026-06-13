/*

It a concept in which for a node i we need to find its kth ancestor.if we think about it it is typical to solve in a good time complexity but via binary lifting we can solve it in O(long(n)) time complexity. The idea is to precompute the 2^j th ancestor for each node i and store it in a table. We make an array up[node][j] where it  means node se  hum jth jump me kaha pahuch skte he
suppose up[node][j]=x means hum jump j me uppr ja skte he pr ye 2 ki power me he toh isliye hum 2^j th ancestor ko store kr rhe he or 2^j ko 2^j-1 + 2^j-1 me tod skte he toh hum up[node][j]=up[up[node][j-1]][j-1] store kr rhe he.



*/

class TreeAncestor {
public:

    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {

        int LOG = log2(n) + 1;

        up.resize(n, vector<int>(LOG, -1));

        for(int i=0;i<n;i++)
            up[i][0] = parent[i];

        for(int j=1;j<LOG;j++){

            for(int node=0;node<n;node++){

                if(up[node][j-1] != -1){
                    up[node][j] =
                        up[up[node][j-1]][j-1];
                }

            }
        }
    }

    int getKthAncestor(int node, int k) {

        for(int bit=0; bit<up[0].size(); bit++){

            if(node == -1) return -1;

            if(k & (1<<bit)){
                node = up[node][bit];
            }
        }

        return node;
    }
};