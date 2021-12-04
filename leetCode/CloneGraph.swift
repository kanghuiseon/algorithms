/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var neighbors: [Node?]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.neighbors = []
 *     }
 * }
 */

class Solution {
    var visited = [Int: Node]()
    func cloneGraph(_ node: Node?) -> Node? {
        guard let node = node else { return nil }
        if let cnode = visited[node.val]{
            return cnode
        }else{
            visited[node.val] = Node(node.val)
        }
        for neighbor in node.neighbors{
            if let cnode = visited[node.val], let cneighbor = cloneGraph(neighbor){
                cnode.neighbors.append(cneighbor)
                visited[node.val] = cnode
                visited[cneighbor.val] = cneighbor
            }
        }
        return visited[node.val]
    }
}
