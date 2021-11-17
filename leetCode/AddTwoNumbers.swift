/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
// 현재 노드가 nil이면 다음 노드도 nil
// 현재 노드가 nil이 아니면 다음 노드 리턴해주기 (nil일수도있고 아닐수도 있음)
// 바로 node!.next를 아래 코드에서 사용했더니 next에 대해서 옵셔널 바인딩을 해줘야해서 함수로 따로 뺐다.
func getNextNode(_ node: ListNode?)->ListNode?{
    if node != nil{
        return node!.next
    }else{
        return nil
    }
}
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var ll1 = l1
        var ll2 = l2
        // head를 따로 만들지 않고 코드를 작성하면 listNode가 마지막 노드만 가지고 리턴한다.
        /*
        -> 이유가 뭘까..? : 내 생각이긴한데 ListNode가 클래스이기 때문에 head 와 listNode가 메모리 상에서 같은 곳을 가리킨다.
        만약 head를 만들지 않고 var listNode로만 코드를 진행하면 while문 마지막에 if문에서 listNode가 listNode.next로 바로 바뀌는 것 같다.
        (next로 연결이 되지 않고)
        그래서 고정 노드인 head를 따로 두고 바뀌는 노드를 listNode로 지정해서 listNode.next = ListNode()를 하면 head가 가리키는 노드에서 점점 연결되게끔 한다.
        */ 
        let head = ListNode()
        var listNode = head
        // carry : 합이 10을 넘길 경우에는 다음 턴에서 carry값을 같이 더해준다. 그렇지 않은 경우에는 carry = 0
        var carry = 0
        var sum = 0
        while ll1 != nil || ll2 != nil{
            if(ll1 != nil){
                sum += ll1!.val
            }
            if(ll2 != nil){
                sum += ll2!.val
            }
            listNode.val = (sum+carry)%10
            carry = (sum+carry) / 10
            sum = 0
            ll1 = getNextNode(ll1)
            ll2 = getNextNode(ll2)
            if(ll1 != nil || ll2 != nil){
                listNode.next = ListNode()
                listNode = listNode.next!
            }
        }
        if carry == 1{
            listNode.next = ListNode(carry)
        }
        return head
    }
}
