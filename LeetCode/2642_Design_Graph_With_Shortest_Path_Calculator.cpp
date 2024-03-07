class Graph {
public:
  vector<vector<int>> wal;
  vector<vector<int>> edges_;
  void floydWarshall() {
    int n = edges_.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (wal[j][k] > wal[j][i] + wal[i][k] && wal[j][i] != 1e9 &&
              wal[i][k] != 1e9) {
            wal[j][k] = wal[j][i] + wal[i][k];
          }
        }
      }
    }
  }

  Graph(int n, vector<vector<int>> &edges) {
    vector<vector<int>> v(n, vector<int>(n, 1e9));

    for (auto it : edges) {
      v[it[0]][it[1]] = it[2];
    }
    edges_ = v;
    wal = edges_;
    for (int i = 0; i < n; i++)
      wal[i][i] = 0;
    floydWarshall();
  }

  void addEdge(vector<int> edge) {
    if (wal[edge[0]][edge[1]] <= edge[2]) {
      return;
    }
    edges_[edge[0]][edge[1]] = edge[2];
    int n = wal.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (wal[i][j] > wal[i][edge[0]] + edge[2] + wal[edge[1]][j]) {
          wal[i][j] = wal[i][edge[0]] + edge[2] + wal[edge[1]][j];
        }
      }
    }
  }

  int shortestPath(int node1, int node2) {
    return (wal[node1][node2] == 1e9 ? -1 : wal[node1][node2]);
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
