
#include <vector>
#include <stack>
#include <queue>

class Graph {
private:
    int V; // ������
    vector<int>* adj; // �ڽӱ�

public:
    Graph(int V); // ���캯��
    void addEdge(int v, int w); // ��ӱ�
    void BFS(int s); // �����������
    void DFS(int s); // �����������
    void dijkstra(int s); // ���·���㷨
    void prim(); // ��С֧�����㷨
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
    vector<bool> visited(V, false); // ��¼�Ƿ���ʹ�
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
    vector<bool> visited(V, false); // ��¼�Ƿ���ʹ�
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // С����
    vector<int> dist(V, INT_MAX); // ��¼�����ľ���

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;
            int weight = 1; // ��Ȩ��Ϊ1

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "���·����\n";
    for (int i = 0; i < V; i++) {
        cout << s << " �� " << i << " �ľ���Ϊ " << dist[i] << endl;
    }
    cout << endl;
}

void Graph::prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // С����
    vector<int> key(V, INT_MAX); // ��¼��MST����СȨ��
    vector<int> parent(V, -1); // ��¼MST��ÿ���ڵ�ĸ��ڵ�
    vector<bool> inMST(V, false); // ��¼�Ƿ���MST��

    pq.push(make_pair(0, 0)); // ��һ���ڵ����
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;
            int weight = 1; // ��Ȩ��Ϊ1

            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "��С֧������\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
    cout << endl;
}