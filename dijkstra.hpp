struct edge
{
public:
    int to;
    int cost;
};

// O(|E|(log|V|))
void dijkstra(std::vector<int> &dist, const std::vector<std::vector<edge>> &graph, int s)
{
    typedef std::pair<int, int> P;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    for (auto &e : dist)
    {
        e = INF;
    }
    dist[s] = 0;
    // P(distance from start, vertex index)
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P cur = pq.top();
        pq.pop();
        int v = cur.second;
        int cost = cur.first;
        if (dist[v] < cost)
        {
            continue;
        }
        for (const auto &next : graph[v])
        {
            if (dist[next.to] > next.cost + dist[v])
            {
                dist[next.to] = next.cost + dist[v];
                pq.push(P(dist[next.to], next.to));
            }
        }
    }
}

// O(|E|)
void restorePath(
    std::vector<int> &path,
    const std::vector<int> &dist,
    const std::vector<std::vector<edge>> &graph,
    int e)
{
    int cur = e;
    path.push_back(e);
    while (dist[cur] != 0)
    {
        for (const auto &n : graph[cur])
        {
            if (dist[n.to] + n.cost == dist[cur])
            {
                path.push_back(n.to);
                cur = n.to;
                break;
            }
        }
    }
    std::reverse(path.begin(), path.end());
}
