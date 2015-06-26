/**
 *@param root, start, end: The root of segment tree and 
 *                         an segment / interval
 *@return: The maximum number in the interval [start, end]
 */
int query(SegmentTreeNode *root, int start, int end) {
    // write your code here
    if(start == root-> start && end == root->end) return root->max;  

    // the boundry of left leaf and right leaf
    int mid = (root->start + root->end) / 2;

    // if query interval is in the left
    if(end <= mid) return query(root->left, start, end);

    // the query interval is in the right; 
    else if(start > mid){
        return query(root->right,start,end);
    }
    else{

        // the query interval is in between, so take the maximum of left and right
        return max(query(root->left,start,mid), query(root->right,mid+1,end));
    }
}