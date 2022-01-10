package Leetcode.Tree.Medium;

import com.sun.source.tree.Tree;

import java.util.HashMap;
import java.util.Stack;

// Definition for a binary tree node.
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

public class DeepestLeavesSum {
    int maxLevel = 0;
    int sumValue = 0;

    public void dfs(TreeNode node, int level) {
        if (level > maxLevel) {
            maxLevel = level;
            sumValue = 0;
        } else if (level == maxLevel) {
            sumValue += node.val;
        }
        if (node.right != null) {
            dfs(node.right, level + 1);
        }
        if (node.left != null) {
            dfs(node.left, level + 1);
        }
    }

    public int solution(TreeNode root) {
        if (root != null) {
            dfs(root, 0);
        }

        return sumValue;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode();
        DeepestLeavesSum d = new DeepestLeavesSum();

        System.out.println(d.solution(root));
    }
}
