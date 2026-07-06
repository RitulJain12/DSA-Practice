class Solution {
public:
    int help(  unordered_set<int>&st, int mycost , vector<vector<int>> &graph,int src, vector<bool>& has)
    {

        if(st.find(src)!=st.end()) return 0;
        st.insert(src);

        int costChild=0;
           
            for(auto &n:graph[src]){

              costChild+=help(st,2,graph,n,has);

            }


            if(costChild==0  && !has[src]) return 0;

            return mycost+costChild;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

           vector<vector<int>> graph(n,vector<int>());

           for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
             graph[e[1]].push_back(e[0]);
           }      
           
           unordered_set<int>st;
      

         return help(st,0,graph,0,hasApple);



    }
};