public class BSTSearch {

    static class Node {
        int data;
        Node left, right;
        public Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    public boolean containsNode(Node root, int target) {
        if (root == null) {
            return false;
        }

        if (root.data == target) {
            return true;
        } else if (target < root.data) {
            return containsNode(root.left, target);
        } else {
            return containsNode(root.right, target);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(15);
        root.left.left = new Node(3);
        root.left.right = new Node(7);

        BSTSearch search = new BSTSearch();

        System.out.println("Is node 7 present? " + search.containsNode(root, 7));
        System.out.println("Is node 20 present? " + search.containsNode(root, 20));
    }
}
