// Last updated: 11/2/2025, 10:29:16 PM
/**
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
class Solution {

    class Info {
        TreeNode root;
        int col;
        int row;
        public Info(TreeNode root, int col, int row) {
            this.root = root;
            this.col = col;
            this.row = row;
        }
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, List<int []>> map = new TreeMap<>();
        Queue<Info>q = new LinkedList<>();
        q.add(new Info(root,0,0));

        while(!q.isEmpty()){
            Info curr = q.remove();

            int col = curr.col;
            int row = curr.row;
            int value = curr.root.val;

            map.putIfAbsent(col, new ArrayList<>());
            map.get(col).add(new int[]{row, value});

            if(curr.root.left != null){
                q.add(new Info(curr.root.left, curr.col - 1, curr.row + 1));
            }

            if(curr.root.right != null){
                q.add(new Info(curr.root.right, curr.col + 1, curr.row + 1));
            }

        }

        List<List<Integer>> ans = new ArrayList<>();
        for( List<int[]> colValues : map.values()){
                        Collections.sort(colValues, (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

            List<Integer> sortedCol = new ArrayList<>();
            for(int [] pair : colValues){
                sortedCol.add(pair[1]);
            }
            ans.add(sortedCol);
        }
        return ans;
    }
}