/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/validate-binary-tree-nodes/description/
*/

/*
  Find the DSU solution here - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Validate%20Binary%20Tree%20Nodes.cpp
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using simple BFS or DFS and Binary Tree Property)
//Find it in my "Binary Tree" repo
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> parent_to_children;
        unordered_map<int, int> child_to_parent;

        for(int i = 0; i<n; i++) {

            int node   = i;
            int leftC  = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1) {
                parent_to_children[node].push_back(leftC);

                if(child_to_parent.find(leftC) != child_to_parent.end()) {
                    return false;
                } else {
                    child_to_parent[leftC] = node;
                }
            }

            if(rightC != -1) {
                parent_to_children[node].push_back(rightC);

                if(child_to_parent.find(rightC) != child_to_parent.end()) {
                    return false;
                } else {
                    child_to_parent[rightC] = node;
                }
            }

        }

        int root = -1;
        
        for(int i = 0; i<n; i++) {
            if(child_to_parent.find(i) == child_to_parent.end()) {
                if(root != -1)
                    return false;
                else
                    root = i;
            }
        }
        if(root == -1)
            return false;

        vector<bool> visited(n, false);
        queue<int> que;
        int count = 1;
        que.push(root);
        visited[root] = true;
        
        while(!que.empty()) { 
            int node = que.front();
            que.pop();

            for(int &child : parent_to_children[node]) {
                if(!visited[child]) {
                    visited[child] = true;
                    count++;
                    que.push(child);
                }
            }

        }

        return count == n; // we should be able to visit all nodes during BFS/DFS

    }
};



//Approach-2 (Using DSU)
//Find here - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Validate%20Binary%20Tree%20Nodes.cpp



/******************************************************** JAVA ********************************************************/
//Approach-1 (Using simple BFS or DFS and Binary Tree Property)
//Find it in my "Binary Tree" repo
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        Map<Integer, List<Integer>> parentToChildren = new HashMap<>();
        Map<Integer, Integer> childToParent = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int node = i;
            int leftChildNode = leftChild[i];
            int rightChildNode = rightChild[i];

            if (leftChildNode != -1) {
                parentToChildren.computeIfAbsent(node, k -> new ArrayList<>()).add(leftChildNode);

                if (childToParent.containsKey(leftChildNode)) {
                    return false;
                } else {
                    childToParent.put(leftChildNode, node);
                }
            }

            if (rightChildNode != -1) {
                parentToChildren.computeIfAbsent(node, k -> new ArrayList<>()).add(rightChildNode);

                if (childToParent.containsKey(rightChildNode)) {
                    return false;
                } else {
                    childToParent.put(rightChildNode, node);
                }
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (!childToParent.containsKey(i)) {
                if (root != -1) {
                    return false;
                } else {
                    root = i;
                }
            }
        }
        if (root == -1) {
            return false;
        }

        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        int count = 1;
        queue.add(root);
        visited[root] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int child : parentToChildren.getOrDefault(node, Collections.emptyList())) {
                if (!visited[child]) {
                    visited[child] = true;
                    count++;
                    queue.add(child);
                }
            }
        }

        return count == n; // we should be able to visit all nodes during BFS/DFS
    }
}



//Approach-2 (Using DSU)
//Find here - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Validate%20Binary%20Tree%20Nodes.cpp
