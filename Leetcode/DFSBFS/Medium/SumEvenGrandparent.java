/*
22/01/14 LeetCode - 1315. Sum of Nodes with Even-Valued Grandparent
 */
package Leetcode.DFSBFS.Medium;

public class SumEvenGrandparent {
    int sum = 0;
    public void dfs(TreeNode node, TreeNode parent, TreeNode grandParent) {
        if (grandParent != null && (grandParent.val % 2) != 0){
            sum += node.val;
        }
        if (node.right != null) {
            dfs(node.right, node, parent);
        }
        if (node.left != null) {
            dfs(node.left, node, parent);
        }
    }

    public int solution(TreeNode root) {
        dfs(root, null, null);

        return sum;
    }

    public static void main(String[] args) {
        SumEvenGrandparent seg = new SumEvenGrandparent();
        TreeNode root = new TreeNode();
        seg.solution(root);
    }
}