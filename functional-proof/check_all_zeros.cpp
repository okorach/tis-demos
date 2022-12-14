template <int n> 
class A  {
  /*@ class invariant POS= n>=0  &&
      \valid(t+(0 .. n−1));
  */
public :
  A() {
    for (int i=0; i<n; i++) {
      t[i] = i;
    }
  }

  void setAt(int index, int value) {
    t[index] = value;
  }
  /*@ assigns \nothing;
      ensures \result!=0 <==>
         (\forall integer j ;0<=j<n ==> t[j]==0) ;
  */
  int check_all_zeros() {
    int k;
    /*@ loop  invariant 0<=k<=n;
        loop  invariant (\forall integer j ; 0<=j<k ==> t[j]==0);
        loop  assigns k ;
        loop  variant n−k ;  */
      for(k=0; k<n; k++)
        if(t[k]!=0)
            return 0;
    return 1;
  }
private:
  int t[n];
};

int main()
{
  A<10> o;
  o.check_all_zeros();
  o.setAt(3, 42);
  o.check_all_zeros();
}
