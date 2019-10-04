

#include <iostream>
using namespace std;
int COUNT = 10;

class Node_reg
{
private:
    int r;
    float x;
    float t;
    int d;
    int n;
    Node_reg *l;
    Node_reg *rt;
    Node_reg *par;
    bool col;

public:
    Node_reg()
    {
        col = true;
        l = NULL;
        rt = NULL;
        par = NULL;
        n = 0;
    }
    Node_reg(int rv, int dv, float xv, float tv)
    {
        n = 1;
        r = rv;
        d = dv;
        x = xv;
        t = tv;
        col = true;
        l = NULL;
        rt = NULL;
        par = NULL;
    }
    Node_reg(Node_reg* reg)
    {
        n = reg->get_n();
        r = reg->get_r();
        d = reg->get_d();
        x = reg->get_x();
        t = reg->get_t();
        col = reg->get_col();
        l = reg->get_l();
        rt = reg->get_rt();
        par = reg->get_par();
    }
    int get_r() const { return r; }
    float get_x() const { return x; }
    float get_t() const { return t; }
    int get_d() const { return d; }
    int get_n() const { return n; }
    int get_col() const { return col; }
    Node_reg *get_par() { return par; }
    Node_reg *get_l() { return l; }
    Node_reg *get_rt() { return rt; }
    float get_balpar() const { return r; }

    void set_balpar(int rv) { r = rv; }
    void set_x(int xv)
    {
        x = xv;
        return;
    }
    void set_d(int dv)
    {
        d = dv;
        return;
    }
    void set_n(int nv)
    {
        n = nv;
        return;
    }
    void set_t(float tv)
    {
        t = tv;
        return;
    }
    void set_col(bool colv)
    {
        col = colv;
        return;
    }
    void set_par(Node_reg *parv)
    {
        par = parv;
        return;
    }
    void set_rt(Node_reg *rv)
    {
        rt = rv;
        return;
    }
    void set_l(Node_reg *lv)
    {
        l = lv;
        return;
    }

    bool greater(Node_reg *nd)
    {
        if (this->r > nd->get_r())
            return true;
        else if (this->r <= nd->get_r())
            return false;
    }

    bool lesser(Node_reg *nd)
    {
        if (this->r < nd->get_r())
            return true;
        else if (this->r >= nd->get_r())
            return false;
    }

    bool isequal(Node_reg *nd)
    {
        if (this->r == nd->get_r())
            return true;
        else
            return false;
    }
};

template <typename T>
class BST
{
private:
    T *root;

public:
    BST<T>(T *r) { root = r; }
    BST<T>() { root = new T(); }
    T *get_root() const
    {
        return root;
    }
    void set_root(T *r) { root = r; }

    int insert(T *nd, T *r, T *prev);
    int remove(T *nd, T *r);
    T *search(T *nd, T *r);
    int balance(T *nd);
    T *srch_smaller(T *nd, T *r);
    T *srch_bigger(T *nd, T *r);
    void print_list(T *nd);
    int count_smaller(T *nd, T *r);
    int count_bigger(T *nd, T *r);
};

class Node_dir
{
private:
    BST<Node_reg> root_reg;
    float x;
    float t;
    int n;
    Node_dir *l;
    Node_dir *rt;
    Node_dir *par;
    bool col;
    int d;

public:
    Node_dir(Node_reg *r)
    {
        root_reg.set_root(r);
        x = r->get_x();
        t = r->get_t();
        col = true;
        l = NULL;
        rt = NULL;
        par = NULL;
        n = 1;
        d = r->get_d();
    }
    Node_dir(Node_dir* dir){
        root_reg.set_root(dir->get_root().get_root());
        x=dir->get_x();
        t=dir->get_t();
        rt=dir->get_rt();
        l = dir->get_l();
        par = dir->get_par();
        n = dir->get_n();
        d = dir->get_d();
    }
    Node_dir()
    {
        n = 0;
        l = NULL;
        rt = NULL;
        par = NULL;
        col = true;
    }
    float get_x() const { return x; }
    float get_t() const { return t; }
    int get_n() const { return n; }
    BST<Node_reg> get_root() const { return root_reg; }
    Node_dir *get_l() const { return l; }
    Node_dir *get_rt() const { return rt; }
    Node_dir *get_par() const { return par; }
    bool get_col() const { return col; }
    float get_balpar() const { return x; }
    int get_d() const { return d; }
    void set_balpar(float xv) { xv = x; }
    void set_l(Node_dir *lv)
    {
        l = lv;
        return;
    }
    void set_n(int nv)
    {
        n = nv;
        return;
    }
    void set_x(float xv)
    {
        x = xv;
        return;
    }
    void set_rt(Node_dir *rv)
    {
        rt = rv;
        return;
    }
    void set_par(Node_dir *parv)
    {
        par = parv;
        return;
    }
    void set_col(bool colv)
    {
        col = colv;
        return;
    }

    void set_t(float tv)
    {
        t = tv;
        return;
    }
    bool greater(Node_dir *nd)
    {

        float xt;
        xt = (nd->get_t() - this->t) * (2 * this->d - 1) + this->x;
        if (xt <= nd->get_x())
            return false;
        else if (xt > nd->get_x())
            return true;
    }

    bool lesser(Node_dir *nd)
    {
        float xt;
        xt = (nd->get_t() - this->t) * (2 * this->d - 1) + this->x;
        if (xt >= nd->get_x())
            return false;
        else if (xt < nd->get_x())
            return true;
    }

    bool isequal(Node_dir *nd)
    {
        float xt;
        xt = (nd->get_t() - this->t) * (2 * this->d - 1) + this->x;

        if (xt != nd->get_x())
            return false;
        else
            return true;
    }
};

template <typename T>
void print(T *root, int space)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print(root->get_rt(), space);

    // Print current node after space
    // count
    cout << endl;
    int i;
    for (i = COUNT; i < space; i++)
        cout << " ";
    cout << root->get_balpar() << " " << root->get_n() << root->get_t();
    cout << "\n";

    // Process left child
    print(root->get_l(), space);
}

class highway
{
private:
    BST<Node_reg> reg_tree;
    BST<Node_dir> dir0_tree;
    BST<Node_dir> dir1_tree;
    float curr;

public:
    highway(int r, int d, float x, float t)
    {
        curr = t;
        Node_reg *regroot = new Node_reg(r, d, x, t);
        reg_tree = BST<Node_reg>(regroot);
        

        if (d == 0)
        {
            Node_reg *regrootd0 = new Node_reg(r, d, x, t);
            Node_dir *dir0_root = new Node_dir(regrootd0);
            dir0_tree = BST<Node_dir>(dir0_root);
            dir1_tree = BST<Node_dir>(NULL);
        }
        if (d == 1)
        {
            Node_reg *regrootd1 = new Node_reg(r, d, x, t);
            Node_dir *dir1_root = new Node_dir(regrootd1);
            dir1_tree = BST<Node_dir>(dir1_root);
            // cout << "dir1 tree created with x=" << dir1_tree.get_root()->get_x() << endl;
            // //Node_dir *dir0_root = new Node_dir();
            dir0_tree = BST<Node_dir>(NULL);
        }
        // cout << "reg tree created with r=" << reg_tree.get_root()->get_r() << endl;
    }

    BST<Node_reg> get_regtree()
    {
        // cout<<"in"<<endl;
        return reg_tree;
    }
    BST<Node_dir> get_dir0tree()
    {
        // cout<<"in"<<endl;
        return dir0_tree;
    }

    float get_curr() const { return curr; }
    void set_curr(float tv)
    {
        curr = tv;
        return;
    }

    int insert(int r, float x, float t, int d);
    int remove(int r, float t);
    void print_t();
    int find_immediate_left(int r, float t);
    int find_immediate_right(int r, float t);
    int count_left(int r, float t);
    int count_right(int r, float t);
    int number_of_crossings(int r, float t);
};

int highway ::insert(int r, float x, float t, int d)
{
    Node_reg *ndreg = new Node_reg(r, d, x, t);
    int ins_reg = reg_tree.insert(ndreg, reg_tree.get_root(), NULL);
    if (ins_reg == 1)
    {
        int ins_dir = 0;
        if (d == 0)
        {
            Node_reg *dirreg = new Node_reg(r, d, x, t);

            Node_dir *nddir = new Node_dir(dirreg);
            Node_dir *nddir1 = new Node_dir(dirreg);
            if (dir0_tree.get_root() != NULL)
            {

                Node_dir *srch = dir0_tree.search(nddir, dir0_tree.get_root());
                if (srch == NULL)
                {
               
                    ins_dir = dir0_tree.insert(nddir, dir0_tree.get_root(), NULL);
                }
                else
                {
                    ins_dir = srch->get_root().insert(dirreg, srch->get_root().get_root(), NULL);
                    // cout << "found existing value insertd in reg tree" << endl;
                    if (ins_dir == 1)
                    {
                        while (srch != NULL)
                        {
                            srch->set_n(srch->get_n() + 1);
                            srch = srch->get_par();
                        }
                    }
                }
                if (ins_dir == 1)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                dir0_tree.set_root(nddir);
                return 1;
            }
        }
        else
        {
            Node_reg *dirreg = new Node_reg(r, d, x, t);
            Node_dir *nddir = new Node_dir(dirreg);

            if (dir1_tree.get_root() != NULL)
            {

                Node_dir *srch = dir1_tree.search(nddir, dir1_tree.get_root());
                if (srch == NULL)
                {
                    ins_dir = dir1_tree.insert(nddir, dir1_tree.get_root(), NULL);
                }
                else
                {
                    ins_dir = srch->get_root().insert(dirreg, srch->get_root().get_root(), NULL);
                    //updating n values in dir1_tree upto root
                    if (ins_dir == 1)
                    {
                        while (srch != NULL)
                        {
                            srch->set_n(srch->get_n() + 1);
                            srch = srch->get_par();
                        }
                    }
                }
                if (ins_dir == 1)
                {
                    return 1;
                }
                else
                {
                
                    return 0;
                }
            }
            else
            {
               
                dir1_tree.set_root(nddir);
               // cout << "new dir tree formed" << endl;

                return 1;
            }
        }
    }
    else
    {
        //cout << "didnt insert in reg tree" << endl;
        return 0;
    }
}

int highway::remove(int r, float t)
{
    Node_reg *reg = new Node_reg(r, 0, 0, t);
    int regdel = 0;
    Node_reg *srch = reg_tree.search(reg, reg_tree.get_root());
    if (srch != NULL)
    {
        int x = srch->get_x();
        int d = srch->get_d();
        int t0 = srch->get_t();
        int dirdel = 0;
        reg->set_x((t - t0) * (2 * d - 1) + x);
        reg->set_d(d);
        regdel = reg_tree.remove(reg, reg_tree.get_root());
        if (regdel == 1)
        {
            // cout << "reg delete successful" << endl;
            if (d == 0)
            {
                Node_dir *dir = new Node_dir(reg);
                Node_dir *dirsrch = dir0_tree.search(dir, dir0_tree.get_root());
                // cout << dirsrch->get_x() << " " << dirsrch->get_t() << "kiid" << endl;
                // cout << "&&" << endl;
                if (!((dirsrch->get_root().get_root()->get_l() == NULL) && (dirsrch->get_root().get_root()->get_rt() == NULL)))
                {
                    // cout << "need to delete from innode tree" << endl;
                    dirdel = dirsrch->get_root().remove(reg, dirsrch->get_root().get_root());
                }
                else
                {
                    // cout << "need to deletefrom dir tree" << endl;
                    dirdel = dir0_tree.remove(dir, dir0_tree.get_root());
                }
                if (dirdel == 1)
                {
                    //cout << "dir delete successful" << endl;
                }
                else
                {
                    //cout << "dirdel not done" << endl;
                }
            }
            if (d == 1)
            {
                Node_dir *dir = new Node_dir(reg);
                Node_dir *dirsrch = dir1_tree.search(dir, dir1_tree.get_root());
                //cout << dirsrch->get_x() << " " << dirsrch->get_t() << "kiid" << endl;
                if (!((dirsrch->get_root().get_root()->get_l() == NULL) && (dirsrch->get_root().get_root()->get_rt() == NULL)))
                {
                   // cout << "need to delete from innode tree" << endl;
                    dirdel = dirsrch->get_root().remove(reg, dirsrch->get_root().get_root());
                }
                else
                {
                    //cout << "need to deletefrom dir tree" << endl;
                    dirdel = dir1_tree.remove(dir, dir1_tree.get_root());
                }
                if (dirdel == 1)
                {
                    //cout << "dir delete successful" << endl;
                    return 1;
                }
                else
                {
                   // cout << "dirdel not done" << endl;
                   return 0;

                }
            }
        }
        else
        {
            //cout << "reg delete failed" << endl;
            return 0;
        }
    }
}

void highway ::print_t()
{
    print<Node_reg>(reg_tree.get_root(), 0);
    cout << endl;
    cout << "dir0tree" << endl;
    print<Node_dir>(dir0_tree.get_root(), 0);
    cout << endl;
    cout << "dir1tree" << endl;
    print<Node_dir>(dir1_tree.get_root(), 0);
}

int highway::find_immediate_left(int r, float t)
{
    Node_reg *reg = new Node_reg(r, 0, 0, t);
    Node_reg *regsrch = reg_tree.search(reg, reg_tree.get_root());
    if (regsrch != NULL)
    {
        float tx = regsrch->get_t();
        int dx = regsrch->get_d();
        float xx = regsrch->get_x();
        reg->set_d(dx);
        reg->set_x((t - tx) * (2 * dx - 1) + xx);
        Node_dir *dir = new Node_dir(reg);
        int imm = -1;
        int immx;
        if (reg->get_d() == 0)
        {
            Node_dir *dirsrch = dir0_tree.search(dir, dir0_tree.get_root());
            if (dirsrch != NULL)
            {
                cout << "dirsrch details" << dirsrch->get_x() << endl;
                Node_dir *dirpar = dirsrch->get_par();
                Node_dir* dirsrcht=dirsrch;
                if (dirsrch->get_l() != NULL)
                {
                    cout<<"left not null"<<endl;
                    dirsrch = dirsrch->get_l();
                    while (dirsrch->get_rt() != NULL)
                        dirsrch = (dirsrch->get_rt());
                    if (dirpar != NULL)
                    {
                        if (dirpar->greater(dirsrch)&&dirpar->lesser(dirsrcht))
                            dirsrch = dirpar;
                    }
                }
                else
                {
                    cout<<"is null"<<endl;
                    if (dirpar != NULL)
                    {
                        // if (dirpar->lesser(dirsrch)){
                        // cout << "here" << endl;
                        // dirsrch=dirpar;
                        // dirpar=dirsrch->get_par();
                        // while(dirpar!=NULL&&dirpar->greater(dirsrch)){
                        //     cout<<dirpar->get_x()<<"hh"<<endl;
                        //     dirsrch = dirpar;
                        //     dirpar=(dirpar->get_par());
                    
                        // }
                        // }
                        while (dirpar != NULL && dirpar->greater(dirsrch))
                            dirpar = dirpar->get_par();
                        
                        dirsrch = dirpar;

                        cout << "nk" << endl;
                    }
                    else{
                        cout<<"pp"<<endl;
                        dirsrch = NULL;
                    }
                }
                // cout << "dirsrch details---" << dirsrch->get_x() << endl;
            }

            //searching for nearer x in other tree
            reg->set_d(1);
            Node_dir *dirtmp = new Node_dir(reg);
            Node_dir *dirtempsrch = dir1_tree.srch_smaller(dirtmp, dir1_tree.get_root());
            if (dirtempsrch != NULL){
               // cout << "dirsrchtmp details" << dirtempsrch->get_x() << endl;
                if(dirtempsrch->greater(dirtmp))dirtempsrch=NULL;
            }
            
                cout << "tempsrch null" << endl;
            cout << "list" << endl;
            if (dirtempsrch != NULL && dirsrch != NULL)
            {
                float x_up = (t - dirsrch->get_t()) * (2 * dirsrch->get_d() - 1) + dirsrch->get_root().get_root()->get_x();
                Node_reg *regtp = new Node_reg(dirsrch->get_root().get_root()->get_r(), dirsrch->get_d(), x_up, t);

                Node_dir *tp = new Node_dir(regtp);

                if (dirtempsrch->greater(tp))
                {
                    dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    cout<<endl;
                    return 1;
                }
                else if (dirtempsrch->lesser(tp))
                {
                    (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    cout << endl;
                    return 1;
                }
                else if (dirtempsrch->isequal(tp))
                {
                    if (dirsrch->lesser(dirtempsrch))
                    {
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    }
                    else
                    {

                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    }
                    cout << endl;
                    return 1;
                }
            }
            else if (dirsrch == NULL && dirtempsrch != NULL)
            {
                dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                cout << endl;

                return 1;
            }
            else if (dirtempsrch == NULL && dirsrch != NULL)
            {

                dirsrch->get_root().print_list(dirsrch->get_root().get_root());
                 return 1;
            }
            else
            {
                cout << "-1" << endl;
                return 0;
            }
        }

        if (reg->get_d() == 1)
        {
            Node_dir *dirsrch = dir1_tree.search(dir, dir1_tree.get_root());
            if (dirsrch != NULL)
            {
                Node_dir *dirpar = dirsrch->get_par();
                if (dirsrch->get_l() != NULL)
                {
                    dirsrch = dirsrch->get_l();
                    while (dirsrch->get_rt() != NULL)
                        dirsrch = (dirsrch->get_rt());
                    if (dirpar != NULL)
                    {
                        if (dirpar->greater(dirsrch))
                            dirsrch = dirpar;
                    }
                }
                else
                {
                    if (dirpar != NULL)
                    {
                        if (dirpar->greater(dirsrch))
                            dirsrch = NULL;
                        else
                            dirsrch = dirpar;
                    }
                    else
                        dirsrch = NULL;
                }
            }

            //searching for nearer x in other tree
           // reg->set_d(0);
            Node_dir *dirtmp = new Node_dir(reg);
            Node_dir *dirtempsrch = dir1_tree.srch_smaller(dirtmp, dir0_tree.get_root());
            //cout << "list" << endl;
            if (dirtempsrch != NULL)
            {
                //cout << "dirsrchtmp details" << dirtempsrch->get_x() << endl;
                if (dirtempsrch->greater(dirtmp))
                    dirtempsrch = NULL;
            }
            if (dirtempsrch != NULL && dirsrch != NULL)
            {
                float x_up = (t - dirsrch->get_t()) * (2 * dirsrch->get_d() - 1) + dirsrch->get_root().get_root()->get_x();
                Node_reg *regtp = new Node_reg(dirsrch->get_root().get_root()->get_r(), dirsrch->get_d(), x_up, t);

                Node_dir *tp = new Node_dir(regtp);
                if (dirtempsrch->greater(tp))
                {
                    dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    cout << endl;
                    return 1;
                }
                else if (dirtempsrch->lesser(tp))
                {
                    (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    cout<<endl;
                    return 1;
                }
                else if (dirtempsrch->isequal(tp))
                {

                    if (dirsrch->lesser(dirtempsrch))
                    {
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    }
                    else
                    {

                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    }
                    cout<<endl;
                    return 1;
                }
            }
            else if (dirsrch == NULL && dirtempsrch != NULL)
            {
                dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                cout<<endl;
                return 1;
            }
            else if (dirtempsrch == NULL && dirsrch == NULL)
            {
                (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                cout<<endl;
                return 1;
            }
            else
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
}

int highway::find_immediate_right(int r, float t)
{
    Node_reg *reg = new Node_reg(r, 0, 0, t);
    Node_reg *regsrch = reg_tree.search(reg, reg_tree.get_root());
    if (regsrch != NULL)
    {
        float tx = regsrch->get_t();
        int dx = regsrch->get_d();
        float xx = regsrch->get_x();
        reg->set_d(dx);
        reg->set_x((t - tx) * (2 * dx - 1) + xx);
        reg->set_t(t);
        Node_dir *dir = new Node_dir(reg);
        if (reg->get_d() == 0)
        {
           Node_dir *dirsrch = dir0_tree.search(dir, dir0_tree.get_root());
            if (dirsrch != NULL)
            {
               // cout << "dirsrch details" << dirsrch->get_x() << endl;
                Node_dir *dirpar = dirsrch->get_par();
                Node_dir* dirsrcht=dirsrch;
                if (dirsrch->get_rt() != NULL)
                {
                    dirsrch = dirsrch->get_rt();
                    while (dirsrch->get_l() != NULL)
                        dirsrch = (dirsrch->get_l());
                    if (dirpar != NULL)
                    {
                        if (dirpar->lesser(dirsrch)&&dirpar->greater(dirsrcht))
                            dirsrch = dirpar;
                    }
                }
                else
                {
                    if(dirpar!=NULL){
                        while (dirpar != NULL && dirpar->lesser(dirsrch))
                            dirpar = dirpar->get_par();
                        dirsrch = dirpar;
                    }
                    else
                        dirsrch = NULL;
                }
            }

            //searching for nearer x in other tree
            //reg->set_d(1);
            Node_dir *dirtmp = new Node_dir(reg);
            Node_dir *dirtempsrch = dir1_tree.srch_bigger(dirtmp, dir1_tree.get_root());
            if (dirtempsrch != NULL)
            {
                //cout << "dirsrchtmp details" << dirtempsrch->get_x() << endl;
                if (dirtempsrch->lesser(dirtmp))
                    dirtempsrch = NULL;
            }
            
          //  cout << "list" << endl;
            if (dirtempsrch != NULL && dirsrch != NULL)
            {

                float x_up = (t - dirsrch->get_t()) * (2 * dirsrch->get_d() - 1) + dirsrch->get_root().get_root()->get_x();
                Node_reg *regtp = new Node_reg(dirsrch->get_root().get_root()->get_r(), dirsrch->get_d(), x_up, t);

                Node_dir *tp = new Node_dir(regtp);
                //cout << tx << " " << t << " " << reg->get_x() << xx << endl;

                if (dirtempsrch->lesser(tp))
                {
                    dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    cout<<endl;
                    return 1;
                }
                else if (dirtempsrch->greater(tp))
                {
                    (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    cout<<endl;
                    return 1;
                }
                else if (dirtempsrch->isequal(tp))
                {
                    if(dirsrch->lesser(dirtempsrch)){
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    }
                    else{
                       
                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    }
                    cout<<endl;
                    return 1;
                }
            }
            else if (dirsrch == NULL && dirtempsrch != NULL)
            {

                dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                cout<<endl;
                return 1;
            }
            else if (dirtempsrch == NULL && dirsrch != NULL)
            {
                (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                cout<<endl;
                return 1;
            }
            else
            {

                cout << "-1" << endl;
                return 0;
            }
        }

        if (reg->get_d() == 1)
        {
            Node_dir *dirsrch = dir1_tree.search(dir, dir1_tree.get_root());
            if (dirsrch != NULL)
            {
                Node_dir *dirpar = dirsrch->get_par();
                if (dirsrch->get_rt() != NULL)
                {
                    dirsrch = dirsrch->get_rt();
                    while (dirsrch->get_l() != NULL)
                        dirsrch = (dirsrch->get_l());
                    if (dirpar != NULL)
                    {
                        if (dirpar->lesser(dirsrch))
                            dirsrch = dirpar;
                    }
                }
                else
                {
                    if (dirpar != NULL)
                    {
                        if (dirpar->lesser(dirsrch))
                            dirsrch = NULL;
                        else
                            dirsrch = dirpar;
                    }
                    else
                        dirsrch = NULL;
                }
            }

            Node_dir *dirtmp = new Node_dir(reg);
            Node_dir *dirtempsrch = dir1_tree.srch_bigger(dirtmp, dir0_tree.get_root());
            if (dirtempsrch != NULL)
            {
               // cout << "dirsrchtmp details" << dirtempsrch->get_x() <<" "<<dirtmp->get_x()<< endl;
                if (dirtempsrch->lesser(dirtmp))
                    dirtempsrch = NULL;
            }
           // cout << "list" << endl;

            if (dirtempsrch != NULL && dirsrch != NULL)
            {
               // cout << tx << "node prev time" << t << "curretn time" << endl;
                float x_up = (t - dirsrch->get_t()) * (2 * dirsrch->get_d() - 1) + dirsrch->get_root().get_root()->get_x();
                Node_reg *regtp = new Node_reg(dirsrch->get_root().get_root()->get_r(), dirsrch->get_d(), x_up, t);

                Node_dir *tp = new Node_dir(regtp);
               // cout << tx << " " << t << " " << tp->get_x() << xx << endl;
                //cout<<tmpdir->get_x()<<" tmpor x l"<<tmpdir->get_t()<<endl;
               // cout << "dirtempsrch" << dirtempsrch->get_x() << " " << dirtempsrch->get_root().get_root()->get_r() << " dirsrch" << dirsrch->get_x() << " " << dirsrch->get_root().get_root()->get_r() << endl;
                if (dirtempsrch->lesser(tp))
                {
                 //   cout << "herellll" << endl;
                    dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    cout<<endl;
                    return 1;
                }
                else if (dirtempsrch->greater(tp))
                {
                  //  cout << "kkkkllllkkkk0" << endl;
                    (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    cout<<endl;
                    return 1;
                }
                else if (dirtempsrch->isequal(tp))
                {

                    if (dirsrch->lesser(dirtempsrch))
                    {
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                    }
                    else
                    {

                        dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                        (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                    }
                    cout<<endl;
                    return 1;
                }
            }
            else if (dirsrch == NULL && dirtempsrch != NULL)
            {
               // cout << "dirtempsrch" << dirtempsrch->get_x() << endl;
                dirtempsrch->get_root().print_list(dirtempsrch->get_root().get_root());
                cout<<endl;
                return 1;
            }
            else if (dirtempsrch == NULL && dirsrch != NULL)
            {
             //   cout << " dirsrch" << dirsrch->get_x() << endl;
                (dirsrch->get_root().print_list(dirsrch->get_root().get_root()));
                cout<<endl;
                return 1;
            }
            else{
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
}

int highway::count_left(int r, float t)
{
    Node_reg *reg = new Node_reg(r, 0, 0, t);
    Node_reg *regsrch = reg_tree.search(reg, reg_tree.get_root());
    if (regsrch != NULL)
    {
        float xx = regsrch->get_x();
        float tt = regsrch->get_t();
        int d = regsrch->get_d();
        reg->set_x((t - tt) * (2 * d - 1) + xx);
        //cout << reg->get_x() << " " << xx << endl;
        reg->set_d(d);
        reg->set_t(t);
        int nl = 0;
        Node_dir *dir = new Node_dir(reg);
        if (d == 0)
        {
            Node_dir *dirsrch = dir0_tree.search(dir, dir0_tree.get_root());
            // cout<<dirsrch->get_x()<<"faf"<<endl;
            int dirtemp = dir1_tree.count_smaller(dir, dir1_tree.get_root());

            if (dirsrch != NULL)
            {
                if (dirsrch->get_l() != NULL)
                {
                    nl += dirsrch->get_l()->get_n();
                }
                Node_dir *t = dirsrch;
                while (t->get_par() != NULL)
                {
                    if (t->greater(t->get_par()))
                    {
                        int tmp = t->get_par()->get_n() - (t->get_n());
                        nl += tmp;
                    }
                    t = t->get_par();
                }
                nl += dirtemp;
                cout << nl << endl;
            }
            //cout << dirtemp << "dusra tree" << nl << "apna tree" << endl;
            
            if (dirsrch == NULL)
            {
                //cout << "dir null";
                return 0;
            }
        }
        else if (d == 1)
        {
            Node_dir *dirsrch = dir1_tree.search(dir, dir1_tree.get_root());

            int dirtemp = dir0_tree.count_smaller(dir, dir0_tree.get_root());

            if (dirsrch != NULL)
            {
                if (dirsrch->get_l() != NULL)
                {
                    nl += dirsrch->get_l()->get_n();
                }
                Node_dir *t = dirsrch;
                while (t->get_par() != NULL)
                {
                    if (t->greater(t->get_par()))
                    {
                        int tmp = t->get_par()->get_n() - (t->get_n());
                        nl += tmp;
                    }
                    t = t->get_par();
                }
                nl += dirtemp;
                cout << nl << endl;
            }
           // cout << dirtemp << "dusra tree" << nl << "apna tree" << endl;
           
            if (dirsrch == NULL)
            {
                //cout << "dir null";
                return 0;
            }
        }
    }
    else
    {
       // cout << "node not found in reg tree" << endl;
       return 0;
    }
}

int highway::count_right(int r, float t)
{
    Node_reg *reg = new Node_reg(r, 0, 0, t);
    Node_reg *regsrch = reg_tree.search(reg, reg_tree.get_root());
    if (regsrch != NULL)
    {
        float xx = regsrch->get_x();
        float tt = regsrch->get_t();
        int d = regsrch->get_d();
        reg->set_x((t - tt) * (2 * d - 1) + xx);
        //cout << reg->get_x() << " " << xx << endl;
        reg->set_d(d);
        int nl = 0;
        Node_dir *dir = new Node_dir(reg);
        if (d == 0)
        {
           // cout << "hey" << endl;
            Node_dir *dirsrch = dir0_tree.search(dir, dir0_tree.get_root());
           // cout << dirsrch->get_x() << endl;

            int dirtemp = dir1_tree.count_bigger(dir, dir1_tree.get_root());

            if (dirsrch != NULL)
            {
                if (dirsrch->get_rt() != NULL)
                {
                    nl += dirsrch->get_rt()->get_n();
                }
                Node_dir *t = dirsrch;
                while (t->get_par() != NULL)
                {
                    if (t->lesser(t->get_par()))
                    {
                        int tmp = t->get_par()->get_n() - (t->get_n());
                        nl += tmp;
                    }
                    t = t->get_par();
                }
                nl += dirtemp;
                cout << nl << endl;
            }
           // cout << dirtemp << "dusra tree" << nl << "apna tree" << endl;
            
            if (dirsrch == NULL)
            {
               // cout << "dir null";
                return 0;
            }
        }
        else if (d == 1)
        {
            Node_dir *dirsrch = dir1_tree.search(dir, dir1_tree.get_root());

            int dirtemp = dir0_tree.count_bigger(dir, dir0_tree.get_root());

            if (dirsrch != NULL)
            {
                if (dirsrch->get_rt() != NULL)
                {
                    nl += dirsrch->get_rt()->get_n();
                }
                Node_dir *t = dirsrch;
                while (t->get_par() != NULL)
                {
                    if (t->lesser(t->get_par()))
                    {
                        int tmp = t->get_par()->get_n() - (t->get_n());
                        nl += tmp;
                    }
                    t = t->get_par();
                }
                nl += dirtemp;
                cout << nl << endl;
            }
            //cout << dirtemp << "dusra tree" << nl << "apna tree" << endl;
           
            if (dirsrch == NULL)
            {
                //cout << "dir null";
                return 0;
            }
        }
    }
    else
    {
       // cout << "node not found in reg tree" << endl;
       return 0;
    }
}

int highway ::number_of_crossings(int r, float t)
{
    int bef, aft;
    Node_reg *reg = new Node_reg(r, 0, 0, 0);
    if (t == this->curr)
    {
        cout << "0" << endl;
        return 1;
    }
    Node_reg *regsrch = reg_tree.search(reg, reg_tree.get_root());
    if (regsrch != NULL)
    {
       // cout << regsrch->get_t() << endl;
        float currt = this->curr;
        reg->set_t(regsrch->get_t());
        float tm = regsrch->get_t();
       // cout << currt << " time " << t << " " << tm << endl;
        float xx = regsrch->get_x();
       // cout << xx << endl;
        int dd = regsrch->get_d();
        reg->set_x((currt - tm) * (2 * dd - 1) + xx);
        reg->set_t(currt);
        //cout << reg->get_x() << "frstx" << endl;
        reg->set_d(dd);
        Node_dir *dir = new Node_dir(reg);
        reg->set_x((t - tm) * (2 * dd - 1) + xx);
        reg->set_t(t);
       // cout << "sec x" << reg->get_x() << endl;
        Node_dir *dirnew = new Node_dir(reg);

        if (dd == 0)
        {
            bef = dir1_tree.count_bigger(dir, dir1_tree.get_root());
            aft = dir1_tree.count_bigger(dirnew, dir1_tree.get_root());
        }
        else
        {
            bef = dir0_tree.count_smaller(dir, dir0_tree.get_root());
            aft = dir0_tree.count_smaller(dirnew, dir0_tree.get_root());
        }
        //cout << bef << " " << aft << endl;
        if(bef>=aft)
            cout << bef - aft << endl;
        else
            cout<<aft-bef<<endl;
        return 1;
    }
    else
    {
        //cout << "not in reg tree" << endl;
        return 0;
    }
}

template <typename T>
void BST<T>::print_list(T *nd)
{
    if (nd == NULL)
        return;
    print_list(nd->get_l());
    cout << nd->get_r() << " ";
    print_list(nd->get_rt());
}

template <typename T>
int BST<T>::insert(T *nd, T *r, T *prev)
{
    if (nd == NULL)
    {
        //cout << "no node to insert as pointer to node to ve inserted is NULL" << endl;
        return 0;
    }
    if (r == NULL)
    {
       // cout << "reached null " << endl;
        // cout << "new node with data" << nd->get_r() << " " << new_n->get_x() << " " << new_n->get_t() << " " << new_n->get_d() << " " << new_n->get_col() << endl;
        nd->set_par(prev);
        if (prev != NULL)
        {
            if (prev->lesser(nd))
            {
                prev->set_rt(nd);
            }
            else
                prev->set_l(nd);
            if (prev->get_col() == false)
            {
                //cout << "inerted in tree without balance" << endl;
                return 1;
            }
            else
                return balance(prev);
        }
        else{
            T* newroot=new T(nd);
            this->set_root(newroot);
           // cout<<"new root formed"<<endl;
            return 1;
        }
    }
    // cout<<r->get_balpar()<<" "<<nd->get_balpar()<<endl;
    if (r->greater(nd))
    {
        r->set_n(r->get_n() + 1);
        //cout << "left in tree" << endl;
        return insert(nd, r->get_l(), r);
    }
    else if (r->lesser(nd))
    {
        r->set_n(r->get_n() + 1);
        //cout << "right in tree" << endl;
        return insert(nd, r->get_rt(), r);
    }
    else if (r->isequal(nd))
    {
        //cout << "value exists in tree" << endl;
        return 0;
    }
    else
    {
        //cout << "error" << endl;
        return 0;
    }
}

template <typename T>
int BST<T>::count_smaller(T *nd, T *r)
{
    int c = 0;
    while (r != NULL)
    {
        if (r->lesser(nd))
        {
            if (r->get_rt() != NULL)
            {
          //      cout << "aggg" << r->get_n() << r->get_rt()->get_n() << endl;
                c += r->get_n() - r->get_rt()->get_n();
            }
            else
                c += r->get_n();
            //cout << c << " nikkkiii" << r->get_x() << endl;
            r = r->get_rt();

            continue;
        }
        if (r->greater(nd) || r->isequal(nd))
        {
            r = r->get_l();
        }
    }
    return c;
}

template <typename T>
int BST<T>::count_bigger(T *nd, T *r)
{
    int c = 0;
    while (r != NULL)
    {
        if (r->greater(nd))
        {
            if (r->get_l() != NULL)
            {
                c += r->get_n() - r->get_l()->get_n();
            }
            else
                c += r->get_n();
            //cout << c << " " << r->get_x() << endl;
            r = r->get_l();
            continue;
        }
        if (r->lesser(nd) || r->isequal(nd))
        {
            r = r->get_rt();
        }
    }
    return c;
}

template <typename T>
int BST<T>::remove(T *x, T *nd)
{
    //cout << "hey" << endl;
    if (nd == NULL)
    {
      //  cout << "value does not exist" << endl;
        return 0;
    }
    //cout << "yo" << endl;
    //cout << x->get_balpar() << " " << nd->get_balpar() << endl;
    if (x->isequal(nd))
    {
      //  cout << "here" << endl;
        if (nd->get_l() == NULL)
        {
            if (nd->get_rt() == NULL)
            {
                if(nd->get_par()!=NULL){
                    if (nd->get_par()->lesser(nd))
                        nd->get_par()->set_rt(NULL);
                    else
                        nd->get_par()->set_l(NULL);
                    return 1;
                }
                else{
                    this->root=NULL;
        //            cout<<"tree empty now"<<endl;
                    return 1;
                }
            }
            else
            {
                if (nd->get_par() != NULL)
                {
                    if (nd->get_par()->lesser(nd))
                    {

                        nd->get_par()->set_rt(nd->get_rt());
                        
                    }
                    else
                    {
                        nd->get_par()->set_l(nd->get_rt());
                    }

                    nd->get_rt()->set_par(nd->get_par());
                    if (nd->get_par()->get_col() && nd->get_col())
                        return balance(nd);
                    return 1;
                }
                else
                {
                    nd->get_rt()->set_par(nd->get_par());
                    this->set_root(nd->get_rt());
                    return 1;
                }
            }
        }
        else if (nd->get_rt() == NULL)
        {
            if (nd->get_par() != NULL)
            {
                if (nd->get_par()->lesser(nd))
                {
                    nd->get_par()->set_rt(nd->get_l());
                }
                else
                {
                    nd->get_par()->set_l(nd->get_l());
                }
                nd->get_l()->set_par(nd->get_par());
                if (nd->get_par()->get_col() && nd->get_col())
                    return balance(nd);
                return 1;
            }
            else
            {
                nd->get_l()->set_par(nd->get_par());
                this->set_root(nd->get_l());
                return 1;
            }
        }
        else
        {
            T *temp = nd->get_rt();
            while (temp->get_l() != NULL)
            {
                temp->set_n(temp->get_n()-1);
                temp = temp->get_l();
            }
            nd->set_balpar(temp->get_balpar());
            if (temp != nd->get_rt())
            {
                if (temp->get_rt() != NULL)
                {
                    temp->get_par()->set_l(temp->get_rt());
                    temp->get_rt()->set_par(temp->get_par());
                    if (temp->get_rt()->get_col() && temp->get_par()->get_col())
                        return balance(temp->get_par());
                }
                else
                {
                    temp->get_par()->set_l(NULL);
                    return 1;
                }
            }
            else
            {
                if (temp->get_rt() != NULL)
                {
                    temp->get_par()->set_rt(temp->get_rt());
                    temp->get_rt()->set_par(temp->get_par());
                    if (temp->get_rt()->get_col() && temp->get_par()->get_col())
                        return balance(temp->get_par());
                }
                else
                {
                    temp->get_par()->set_rt(NULL);
                    return 1;
                }
            }
        }
    }
    else if (x->lesser(nd))
    {
        x->set_n(x->get_n() -1);
        // cout<<"going left for deletion"<<endl;

        return remove(x, nd->get_l());
    }
    else
    {
        x->set_n(x->get_n() - 1);
        //   cout << "going right for deletion" << endl;
        return remove(x, nd->get_rt());
    }
}

template <typename T>
int BST<T>::balance(T *prev)
{
    while (prev->get_par() != NULL)
    {
        if (prev->lesser(prev->get_par()))
        {
            if (prev->get_par()->get_rt() != NULL && prev->get_par()->get_rt()->get_col() == true)
            {
                prev->set_col(false);
                prev->get_par()->set_col(true);
                prev->get_par()->get_rt()->set_col(false);

                // cout << "red node inserted with parent color flip" << endl;
                if (prev->get_par() != NULL)
                {
                    // cout << "going up to balance" << endl;
                    prev = prev->get_par();
                    continue;
                }
                else
                {
                    // cout << "at root color change" << endl;
                    prev->set_col(true);
                    // cout << "balance reached upto root-- root turned black" << endl;
                }
                return 1;
            }
            else
            {
                T *prevp = prev->get_par();
                if (prevp->get_par() != NULL)
                {
                    if (prevp->get_par()->greater(prevp))
                    {
                        prevp->get_par()->set_l(prev);
                    }
                    else
                    {
                        prevp->get_par()->set_rt(prev);
                    }
                }
                // cout << "right shift" << endl;
                prev->set_par(prevp->get_par());
                prevp->set_l(prev->get_rt());
                int b = 0;
                if (prevp->get_l() != NULL)
                {
                    prevp->get_l()->set_par(prevp);
                    b = prevp->get_l()->get_n();
                    // prevp->set_n(prevp->get_n()-(prev->get_n())+(prevp->get_l()->get_n()));
                }
                prev->set_rt(prevp);
                prevp->set_par(prev);
                prevp->set_col(true);
                prev->set_col(false);
                prevp->set_n(prevp->get_n() - prev->get_n() + b);
                prev->set_n(prev->get_n() - b + prevp->get_n());
                if (prev->get_par() == NULL)
                    this->root = prev;

                return 1;
            }
        }
        else
        {
            if (prev->get_par()->get_l() != NULL && prev->get_par()->get_l()->get_col() == true)
            {

                prev->set_col(false);
                prev->get_par()->set_col(true);
                prev->get_par()->get_l()->set_col(false);

                // cout << "red node inserted with parent color flip" << endl;
                if (prev->get_par() != NULL)
                {
                    prev = prev->get_par();
                    continue;
                }
                else
                {
                    prev->set_col(true);
                    // cout << "balance reached upto root-- root turned black" << endl;
                }
                return 1;
            }
            else
            {
                // cout << "left shift" << endl;
                T *prevp = prev->get_par();
                if (prevp->get_par() != NULL)
                {
                    if (prevp->get_par()->greater(prevp))
                    {
                        prevp->get_par()->set_l(prev);
                    }
                    else
                    {
                        prevp->get_par()->set_rt(prev);
                    }
                }
                prev->set_par(prevp->get_par());
                prevp->set_rt(prev->get_l());
                int b = 0;

                if (prevp->get_rt() != NULL)
                {
                    prevp->get_rt()->set_par(prevp);
                    b = prevp->get_rt()->get_n();
                }
                prev->set_l(prevp);
                prevp->set_par(prev);
                prevp->set_col(true);
                prev->set_col(false);
               // cout << prevp->get_n() << prev->get_n() << b << endl;
                prevp->set_n(prevp->get_n() - prev->get_n() + b);
                prev->set_n(prevp->get_n() + prev->get_n() - b);
                if (prev->get_par() == NULL)
                    this->root = prev;
                return 1;
            }
        }
    }
    if (prev->get_par() == NULL && prev->get_col() == true)
    {
        prev->set_col(false);
        //  cout << "root color flip" << endl;
        return 1;
    }
}

template <typename T>
T *BST<T>::search(T *nd, T *root)
{
    if (root == NULL)
    {
        //cout << "root null" << endl;
        return NULL;
    }
    //cout << nd->get_t() << " nfjkfn" << root->get_t() << endl;
    if (nd->isequal(root))
    {
      //  cout << "found existing value in tree" << endl;
        return root;
    }
    if (nd->lesser(root))
    {
        //cout << "l" << endl;

        return search(nd, root->get_l());
    }
    else
    {
        //cout << "r" << endl;
        return search(nd, root->get_rt());
    }
}

template <typename T>
T *BST<T>::srch_smaller(T *nd, T *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    //cout << "kkkrr" << root->get_x() << endl;
    if (root->lesser(nd))
    {
      //  cout << "good" << endl;
        if (root->get_rt() != NULL)
            return srch_smaller(nd, root->get_rt());
        else
            return root;
    }
    else if (root->greater(nd) || root->isequal(nd))
    {
        if (root->get_l() != NULL)
            return srch_smaller(nd, root->get_l());
        else
        {
            if (root->get_par() != NULL)
                return root->get_par();
            else
                return root;
        }
    }
}

template <typename T>
T *BST<T>::srch_bigger(T *nd, T *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    //cout << "kkkrr" << root->get_x() << endl;
    if (root->greater(nd))
    {
      //  cout << "good" << endl;
        if (root->get_l() != NULL)
            return srch_bigger(nd, root->get_l());
        else
            return root;
    }
    else if (root->lesser(nd) || root->isequal(nd))
    {
        if (root->get_rt() != NULL)
            return srch_bigger(nd, root->get_rt());
        else
        {
            if (root->get_par() != NULL)
                return root->get_par();
            else
                return root;
        }
    }
}



int main()
{

    int r, d;
    float x, t, curr;
    int res = 0;
    int op;
    curr = 0;
  //  cout << "highway emppty" << endl;
    cin >> op;
    int c;
    cin >> c >> r >> x >> t >> d;
    highway road(r, d, x, t);
    for (int i = 0; i < op-1; i++)
    {
        road.print_t();
        cin >> c;
        if (c == 1)

        {
            cin >> r >> x >> t >> d;
            if(t>=curr)
                res = road.insert(r, x, t, d);
        }
        if (c == 2)
        {
            cin >> r >> t;
            if (t >= curr)
                res = road.remove(r, t);
        }
        if (c == 3)
        {
            cin >> r >> t;
            if (t >= curr)
                res = road.find_immediate_left(r, t);
        }
        if (c == 4)
        {
            cin >> r >> t;
            if (t >= curr)
                res = road.find_immediate_right(r, t);
        }
        if (c == 5)
        {
            cin >> r >> t;
            if (t >= curr)
                res = road.count_left(r, t);
        }
        if (c == 6)
        {
            cin >> r >> t;
            if (t >= curr)
                res = road.count_right(r, t);
        }
        if (c == 7)
        {
            cin >> r >> t;
            if (t >= curr)
                res = road.number_of_crossings(r, t);
        }
        if (res){
            curr=t;
            road.set_curr(t);
        }
        
    }
}
