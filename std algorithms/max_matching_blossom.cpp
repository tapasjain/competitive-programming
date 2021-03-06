// vertices 0 to n-1
// xorfire codechef HAMILG solution

#define VI vector<int>
#define VVI vector< VI >

struct dantes {
	const int N;
	const VVI adj;
	VI matched;

	int matching;

	dantes(VVI adj) : N(adj.size()), adj(adj), matched(N, -1), matching(0) {
		for (int i = 0; i < N; ++i) {
			if (matched[i] == -1) {
				for(int j = 0; j < adj[i].size(); ++j) {
					if (matched[adj[i][j]] == -1) {
						matched[i] = adj[i][j];
						matched[adj[i][j]] = i;
						matching++;
						break;
					}
				}
			}
		}
	}

	int max_matching() {
		int result = 0;

		for(int i = 0; i < N; ++i) {
			if (matched[i] != -1)
				continue;

			VI previous(N, -1);

			int v = find_augmenting_path(i, previous);

			if (v != -1)
				result++;

			while(v != -1) {
				int u = matched[previous[v]];
				matched[v] = previous[v];
				matched[previous[v]] = v;
				v = u;
			}
		}
		return result + matching;
    }

	int find_augmenting_path(int root, VI &previous) {
		VI base(N);
		for(int i = 0; i < N; ++i)
		base[i] = i;

		VI visited(N);
		visited[root] = 0;

		queue<int> q;
		q.push(root);

		while(!q.empty()) {
			int v = q.front(); q.pop();

			for(int j = 0; j < adj[v].size(); ++j) {
				int u = adj[v][j];

				if (u == matched[v])
					continue;

				if (base[v] == base[u])
					continue;

				// Found blossom
				if (visited[u]) {
					int blossom_base = -1;

					VI track(N, 0);

					int u_track = u;

					while(1) {
						u_track = base[u_track];
						track[u_track] = true;

						if (matched[u_track] == -1)
							break;
						u_track = previous[matched[u_track]];
					}

					int v_track = v;

					while(1) {
						v_track = base[v_track];
						if (track[v_track]) {
							blossom_base = v_track;
							break;
						}
						v_track = previous[matched[v_track]];
					}


					VI blossom(N, 0);
					update_blossom (v, blossom_base, u, base, blossom, previous);
					update_blossom (u, blossom_base, v, base, blossom, previous);

					for (int i = 0; i < N; ++i) {
						if (blossom[base[i]]) {
							base[i] = blossom_base;
							if (!visited[i]) {
								q.push(i);
								visited[i] = true;
							}
						}
					}
				}
				else if (previous[u] == -1) {
					previous[u] = v;
					if (matched[u] != -1) {
						if (!visited[matched[u]]) {
							q.push(matched[u]);
							visited[matched[u]] = true;
						}
					}
					else {
						return u;
					}
				}
			}
		}

		return -1;
    }

	void update_blossom(int v, int blossom_base, int u, const VI &base, VI &blossom, VI &previous) {
		while (base[v] != blossom_base) {
			blossom[base[v]] = blossom[base[matched[v]]] = true;
			previous[v] = u;
			u = matched[v];
			v = previous[matched[v]];
		}
	}
};