
#include <vector>
#include <stack>
#include <queue>

class Graph {
private:
    int V; // 顶点数
    vector<int>* adj; // 邻接表

public:
    Graph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void BFS(int s); // 广度优先搜索
    void DFS(int s); // 深度优先搜索
    void dijkstra(int s); // 最短路径算法
    void prim(); // 最小支撑树算法
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s) {//BFS
    vector<bool> visited(V, false); 
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

void Graph::DFS(int s) {//DFS
    vector<bool> visited(V, false); 
    stack<int> st;

    visited[s] = true;
    st.push(s);

    while (!st.empty()) {
        s = st.top();
        cout << s << " ";
        st.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                st.push(*i);
            }
        }
    }
}

void Graph::dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> dist(V, INT_MAX); 

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;
            int weight = 1; 

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "最短路径：\n";
    for (int i = 0; i < V; i++) {
        cout << s << " 到 " << i << " 的距离为 " << dist[i] << endl;
    }
    cout << endl;
}

void Graph::prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> key(V, INT_MAX); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 

    pq.push(make_pair(0, 0)); 
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;
            int weight = 1; 

            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "最小支撑树：\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
    cout << endl;
}
