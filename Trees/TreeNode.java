
/**
 * LEETCODE PROBLEM 94: BINARY TREE INORDER TRAVERSAL
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Example 1:
Input: root = [1,null,2,3]

Output: [1,3,2]






 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
  }
  
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        TreeNode curr = root;
        while(curr != null){
            if(curr.left != null){
                TreeNode temp = curr.left;
                while(temp.right != null && temp.right != curr){
                    temp = temp.right;
                }
                if(temp.right == null){
                    temp.right = curr;
                    curr = curr.left;
                }
                else{
                    temp.right = null;
                    inorder.add(curr.val);
                    curr = curr.right;
                }
            }
            else{
                inorder.add(curr.val);
                curr = curr.right;
            }
        }
        return inorder;
    }
}