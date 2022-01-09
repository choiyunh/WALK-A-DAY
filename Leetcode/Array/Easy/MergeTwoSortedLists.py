# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()
        cur = head
        while True:
            print(l1)
            print(l2)
            print(head)
            if l1 is None:
                if l2 is None:
                    break
                else:
                    cur.next = ListNode(l2.val)
                    l2 = l2.next
                    cur = cur.next
                    continue
            if l2 is None:
                cur.next = ListNode(l1.val)
                l1 = l1.next
                cur = cur.next
                continue

            if l1.val <= l2.val:
                cur.next = ListNode(l1.val)
                l1 = l1.next
            else:
                cur.next = ListNode(l2.val)
                l2 = l2.next

            cur = cur.next
        return head.next
