#pragma once
#include <iostream>
#include <algorithm>

template <class K>
struct BSTreeNode
{
    K _key;
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
    BSTreeNode(const K& key)
        :_key(key)
         ,_left(nullptr)
         ,_right(nullptr)
    {
    }
    
};

template <class T>
class BSTree
{
    typedef BSTreeNode<T> BTNode;
    public: typedef BTNode* iterator;
    public:
        BSTree()
            :_root(nullptr)
        {}
        //增
        void insert(const T& key)
        {
            BTNode *newNode = new BTNode(key); // 若创建失败会抛异常
            //空树直接插入
            if(_root == nullptr)
            {
                _root = newNode;
                return;
            }
            
            //非空树找到合适位置插入
           iterator cur = _root;
           iterator parent = nullptr;
           while(cur)
           {
               if(key > cur->_key)
               {
                   parent = cur;
                   cur = cur->_right;
               }
               else if(key < cur->_key)
               {
                   parent = cur;
                   cur = cur->_left;
               }
               else 
               {
                    return ;
               }
           }
           
           //判断插入到父亲的左还是右
           if(key > parent->_key)
           {
                parent->_right = newNode;
           }
           else 
           {
                parent->_left = newNode;
           }

        }
        
        void _inorder(BTNode* root)
        {
            if(root == nullptr)
            {
                return ;
            }

            _inorder(root->_left);
            std::cout << root->_key ;
            _inorder(root->_right);
        }

        void inorder()
        {
            _inorder(_root);
            std::cout << std::endl;
        }

        //查
        iterator find(const T& key)
        {
            iterator cur = _root;
            while(cur)
            {
                if(key > cur->_key)
                {
                    cur = cur->_right;
                }
                else if(key < cur->_key)
                {
                    cur = cur->_left;
                }
                else 
                {
                    return cur;
                }
            }

            return nullptr;
        }
        
        //删
        bool erase(const T& key)
        {
            // key没有左右孩子, 直接将父亲的孩子指针置NULL
            // key只有一个孩子, 让父亲的孩子指针指向key结点的孩子结点
            // key结点既有左孩子又有右孩子。将左树最右边的结点或者右树最左的结点与key结点替换后删除该节点。
            
            iterator parent = _root;
            iterator cur = _root;
            while(cur)
            {
                if(key > cur->_key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if(key < cur->_key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else 
                {
                    //找到了，删除
                    
                    if(cur->_left == nullptr) // 左孩子为NULL,右孩子可能存在
                    {
                        if(cur == _root) // parent和cur是根
                        {
                            _root = cur->_right;
                            delete cur;
                            continue;
                        }
                        
                        // parent不是根
                        if(cur == parent->_left)
                        {
                            parent->_left = cur->_right;
                        }
                        else 
                        {
                            parent->_right = cur->_right;
                        }
                        delete cur;
                        return true;
                    }
                    else if(cur->_right == nullptr)  // 左孩子存在, 右孩子为NULL
                    {
                        if(cur == _root)
                        {
                            _root = cur->_left;
                            delete cur;
                            continue;
                        }

                        // 父亲不是根
                        if(cur == parent->_left)
                        {
                            parent->_left = cur->_left; 
                        }
                        else 
                        {
                            parent->_right = cur->_left;
                        }
                        delete cur;
                    }
                    else //左右孩子都存在
                    {
                        // 找左树最大的结点(最右结点)
                        iterator leftMax = cur->_left; //找左树最大结点 
                        iterator lmParent = cur;  //找左树最大结点父结点
                        while(leftMax->_right)
                        {
                            lmParent = leftMax;
                            leftMax = leftMax->_right;
                        }
                        //走到这说明leftMax的右一定是NULL,但是左孩子不一定是null
                        cur->_key = leftMax->_key;

                        //更改和leftMax的链接关系
                        if(leftMax == cur->_left)
                        {
                            lmParent->_left = leftMax->_left;
                        }
                        else 
                        {
                            lmParent->_right = leftMax->_left;
                        }

                        delete leftMax;

                    }
                }
            }

            //没找到
            return false;
        }
    private:
        BTNode* _root;
};

