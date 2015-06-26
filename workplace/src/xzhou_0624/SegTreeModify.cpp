 /**
 *@param root, index, value: The root of segment tree and 
 *@ change the node's value with [index, index] to the new given value
 *@return: void
 */

 // this is not the optimal solution, but pass the tests
void modify(SegmentTreeNode *root, int index, int value) {
    // write your code here

    // for the leave, just simple change the max value
    if(root->start == root->end){
        root-> max = value;
        return;
    }
    int mid = (root->start + root->end) / 2;

    // this block is to modify the max value of the root
    // if the new value is bigger than original max, just reset the max
    if(value >= root->max){
        root->max = value;
    } 
    else{
        // if the original max is the max of the branch is modified
        // in this case is left branch
        if(index <= mid && root->max == root-> left ->max){
            // modify it and update the max value in that branch
            modify(root->left,index,value);
            // just take the new max
            root->max = max(root->left->max, root->right->max);

        }
        // right branch
        else if(index > mid && root->max == root->right -> max){
            modify(root->right,index,value);
            root->max = max(root->left->max, root->right->max);
        }

        // anything else there is no need to change the root max
    }
        
    // here is not the optimal solution, since we already did the recursion once for some cases
    if(index <= mid){
        modify(root->left,index,value);
        
    }
    else{
        modify(root->right,index,value);

    }
}