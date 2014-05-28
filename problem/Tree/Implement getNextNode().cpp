/*

Give a chapter tree as below:

           1
        /   |   \
     1.1   1.2  1.3
     /     /
  1.1.1   1.2.1   

and operations getParent(), getNextSibling(), getFirstChild()

Implement getNextNode(node)

Example:

1.1.1's next is 1.2

1.2.1's next is 1.3

*/


/*

solution: for a node, if it has child, return first child, otherwise, if it has sibling, return next sibling, 
otherwise, return its partent sibling


*/


Node* GetNextNode(Node *node) {
   assert(node != NULL);

   Node* next = node->GetFirstChild();
   if(next) return next;

   next = node->GetSlibing();

   if(next) return next;

   next = node->GetParent();

   while (next) {

      next = next->GetSlibing();
      if(next) return next;
      next = next->GetParent();
   }

   return NULL;
}
