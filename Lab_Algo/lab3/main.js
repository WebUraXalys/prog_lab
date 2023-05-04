class Edge {
  constructor(u, v, weight) {
    this.u = u;
    this.v = v;
    this.weight = weight;
  }
}

function kruskal(edges, n) {
  let parent = [...Array(n).keys()];
  let rank = new Array(n).fill(0);
  edges.sort((a, b) => a.weight - b.weight);
  let result = [];
  for (let edge of edges) {
    let u = edge.u;
    let v = edge.v;
    if (find(u, parent) !== find(v, parent)) {
      union(u, v, parent, rank);
      result.push(edge);
    }
  }
  return result;
}

function find(u, parent) {
  if (parent[u] !== u) {
    parent[u] = find(parent[u], parent);
  }
  return parent[u];
}

function union(u, v, parent, rank) {
   let root_u = find(u, parent);
   let root_v = find(v, parent);
   if (rank[root_u] < rank[root_v]) {
      parent[root_u] = root_v;
   } else if (rank[root_u] > rank[root_v]) {
      parent[root_v] = root_u;
   } else {
      parent[root_v] = root_u;
      rank[root_u] += 1;
   }
}