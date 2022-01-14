package Leetcode.DFSBFS.Easy;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

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