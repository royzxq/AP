
// trival recursive solution, nothing to say
SegmentTreeNode * build(int start, int end) {
    // write your code here
    if(end < start) return nullptr;
    SegmentTreeNode * root = new SegmentTreeNode(start, end);
    if(start != end){
        root -> left = build(start, (start+end)/2);
        root -> right = build((start+end)/2+1, end);
    }
    return root;
}