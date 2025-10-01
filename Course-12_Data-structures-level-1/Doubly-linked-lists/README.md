🟢 Definition

A Doubly Linked List is a sequence of nodes where each node stores:

 - Data – the actual value you care about.

 - A pointer to the next node (next).

 - A pointer to the previous node (prev).

 - So each node has two links


 🟩 Key Operations You’ll Learn

Insertion

    At beginning

    At end

    After/before a given node

    Deletion

    From beginning

    From end

    Specific node by value or position

    Traversal

    Forward traversal (head → tail)

    Backward traversal (tail → head)

    Search

    Reverse (very easy in DLL because of prev)

🟢 Advantages

    Can be traversed in both directions.

    Easier to delete a node if we have a pointer to it (no need to find the previous node first).

    More flexible for certain data structures (like Deques, Undo/Redo stacks).

🔴 Disadvantages

    Uses more memory because of the extra pointer.

    Slightly more complex to implement.

    A bit slower for insertions because you need to update two pointers (prev and next) instead of just one.