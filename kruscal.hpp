class DisjointSet
{
private:
    std::vector<int> parent;

public:
    DisjointSet(int n)
    : parent(n, -1)
    {
    }
    
    bool unite(int x, int y){
        x = root(x);
        y = root(y);

        if (x != y)
        {
            if (x > y)
            {
                std::swap(x, y);
            }
            parent[x] += parent[y];
            parent[y] = x;
        }

        return x != y;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

private:
    int root(int x){
        return parent[x] < 0 ? x : parent[x] = root(parent[x]);
    }
};

struct edge{
	int u,v;
	double cost;
	bool operator<(const edge &e)const{ return cost<e.cost; }
};

vector<edge> kruskal(int n, vector<edge> E){ 
	vector<edge> M;
	sort(E.begin(),E.end());

	DisjointSet U(n);
	for(int i=0;i<E.size();i++){
		int u=E[i].u,v=E[i].v;
		if(!U.same(u, v)){
			U.unite(u,v);
			M.push_back(E[i]);
		}
	}
	return M;
}