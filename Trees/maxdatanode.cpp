#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this -> data = data;
		}
};

TreeNode<int>* takeinput(){
	int rootData;
	cout << "Enter Root Data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		int numofchild;
		cout << "Enter no of children of " << front -> data << endl;
		cin >> numofchild;
		
		for(int i=0;i<numofchild;i++){
			int childData;
			cout << "Enter " << i << "th child of " << front -> data << endl;
			cin >> childData;
			
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){
	TreeNode<int>* maximum = root;
	for(int i=0;i<root->children.size();i++){
		TreeNode<int>* small = maxDataNode(root->children[i]);
		if(maximum -> data < small -> data){
			maximum = small;
		}
	}
	return maximum;
}

void printTree(TreeNode<int>* root){
	if(root == NULL){	//Edge case.
		return;
	}
	
	queue<TreeNode<int>*> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode<int>* front = q.front();
		q.pop();
		
		cout << front -> data << ":";
		for(int i=0;i<front->children.size();i++){
			q.push(front -> children[i]);
			if(front -> children.size() - 1 != i){
				cout << front -> children[i] -> data << ",";
			}else{
				cout << front -> children[i] -> data;
			}
		}
		cout << endl;
	}
}

int main(){
	TreeNode<int>* root = takeinput();
	
	printTree(root);
	
	TreeNode<int>* ans = maxDataNode(root);
	if(root != NULL){
		cout << ans -> data << endl;
	}

	return 0;
}
