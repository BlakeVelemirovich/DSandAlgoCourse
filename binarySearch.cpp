#include <iostream>
using namespace std;

int binarySearch(int array[], int left, int right, int target) {
    int middle = (right + left) / 2;
    
    if (array[middle] == target) {
        return middle;
    } else if (array[middle] > target) {
        return binarySearch(array, left, middle - 1, target);
    } else {
        return binarySearch(array, middle + 1, right, target);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 9;
    int n = sizeof(array) / sizeof(array[0]);
    
    int answer = binarySearch(array, 0, n-1, target);
    
    cout << "Running the binary search recursive algorithm with the following target: " << target << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "The index is: " << answer << endl;
    
    cout << R"(
         .            )        )
                  (  (|              .
              )   )\/ ( ( (
      *  (   ((  /     ))\))  (  )    )
    (     \   )\(          |  ))( )  (|
    >)     ))/   |          )/  \((  ) \
    (     (      .        -.     V )/   )(    (
     \   /     .   \            .       \))   ))
       )(      (  | |   )            .    (  /
      )(    ,'))     \ /          \( `.    )
      (\>  ,'/__      ))            __`.  /
     ( \   | /  ___   ( \/     ___   \ | ( (
      \.)  |/  /   \__      __/   \   \|  ))
     .  \. |>  \      | __ |      /   <|  /
          )/    \____/ :..: \____/     \ <
   )   \ (|__  .      / ;: \          __| )  (
  ((    )\)  ~--_     --  --      _--~    /  ))
   \    (    |  ||               ||  |   (  /
         \.  |  ||_             _||  |  /
           > :  |  ~V+-I_I_I-+V~  |  : (.
          (  \:  T\   _     _   /T  : ./
           \  :    T^T T-+-T T^T    ;<
            \..`_       -+-       _'  )
  )            . `--=.._____..=--'. ./         (
                        (     (                *         (       (    (     (        )           
 (             *   )   )\ )  )\ )    (      (  `        )\ )    )\ ) )\ )  )\ )  ( /(   *   )   
 )\ )    (   ` )  /(  (()/( (()/(    )\     )\))(   (  (()/(   (()/((()/( (()/(  )\())` )  /(   
(()/(    )\   ( )(_))  /(_)) /(_))((((_)(  ((_)()\  )\  /(_))   /(_))/(_)) /(_))((_)\  ( )(_))  
 /(_))_ ((_) (_(_())  (_))_|(_))   )\ _ )\ (_()((_)((_)(_))_   (_)) (_))_ (_))    ((_)(_(_())   
(_)) __|| __||_   _|  | |_  | |    (_)_\(_)|  \/  || __||   \  |_ _| |   \|_ _|  / _ \|_   _|   
  | (_ || _|   | |    | __| | |__   / _ \  | |\/| || _| | |) |  | |  | |) || |  | (_) | | |     
   \___||___|  |_|    |_|   |____| /_/ \_\ |_|  |_||___||___/  |___| |___/|___|  \___/  |_|     
                                                                                             
    )" << endl;
}