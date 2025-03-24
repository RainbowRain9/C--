<!--
 * @Author: RainbowRain9
 * @Date: 2025-03-21 16:47:41
 * @LastEditTime: 2025-03-21 16:51:03
 * @FilePath: \C++\📔MyNote\! ListNode链表.md
 * @Description: 
-->
# ! ListNode链表

## 虚拟头节点

```cpp
ListNode* dummy = new ListNode(0, head);
ListNode* p0 = dummy;
```

## 反转链表

### 反转整个链表
[206. 反转链表](<206.反转链表.md>)
```cpp
ListNode* cur = head;
ListNode* pre = NULL;
while (cur != NULL) {
    ListNode* nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
}
```

### 反转链表的一部分
[92. 反转链表 II](<92.反转链表 II.md>)
```cpp
ListNode* cur = head;
ListNode* pre = NULL;
for (int i = 0; i < left - 1; i++) {
    p0 = p0->next;
}
ListNode* cur = p0->next;
for (int i = 0; i < right - left + 1; i++) {
    ListNode* nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
}
p0->next->next = cur;
p0->next = pre;
return dummy->next;
```
