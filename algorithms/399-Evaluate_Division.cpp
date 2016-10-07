class Solution {
public:
    struct node{
        string val;
        double weight;
        node(string val1, double weight1):val(val1),weight(weight1){}
    };
    double DFS(map<string, vector<node>>& graph, set<string>& visited,string first, string second)
    {
        vector<node> nodes = graph[first];
        visited.insert(first);
        for(vector<node>::iterator it = nodes.begin(); it != nodes.end(); it++)
        {
            if(visited.find(it->val) == visited.end())
            {
                visited.insert(it->val);
                if(it->val == second)
                    return it->weight;
                else
                {
                    double res = DFS(graph, visited,it->val, second);
                    if(res != -1.0)
                        return it->weight*res;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<string> vertex;
        map<string, vector<node>> graph;
        vector<pair<string, string>>::iterator it = equations.begin();
        vector<double>::iterator it1 = values.begin();
        for(; it != equations.end(); it++, it1++)
        {
            if(find(vertex.begin(), vertex.end(), it->first) == vertex.end())
                vertex.push_back(it->first);
            if(find(vertex.begin(), vertex.end(), it->second) == vertex.end())
                vertex.push_back(it->second);
            node node1(it->second, *it1);
            map<string, vector<node>>::iterator it2;
            if((it2=graph.find(it->first)) != graph.end())
            {
               it2->second.push_back(node1); 
            }
            else
            {
                vector<node> nodes;
                nodes.push_back(node1);
                graph[it->first] = nodes;
            }
            
            node node2(it->first, 1/(*it1));
            map<string, vector<node>>::iterator it4;
            if((it4=graph.find(it->second)) != graph.end())
            {
               it4->second.push_back(node2); 
            }
            else
            {
                vector<node> nodes;
                nodes.push_back(node2);
                graph[it->second] = nodes;
            }
        }
        vector<double> result;
        for(vector<pair<string, string>>::iterator it3=queries.begin(); it3 != queries.end(); it3++)
        {
            set<string> visited;
            if(find(vertex.begin(), vertex.end(), it3->first) == vertex.end() || 
            find(vertex.begin(), vertex.end(), it3->second) == vertex.end())
                result.push_back(-1.0);
            else if(it3->first == it3->second)
                result.push_back(1.0);
            else
            {
                result.push_back(DFS(graph, visited,it3->first, it3->second));
            }
        }
        return result;
    }
};