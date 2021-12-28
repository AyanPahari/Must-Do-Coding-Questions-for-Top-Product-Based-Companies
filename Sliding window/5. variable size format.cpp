//this is the general format for the variable size sliding window

// while(j<size){
//     calculations....

//     if(condition<K){
//         j++;     //doing this to hit the window size
//     }
//     else if(condition==K){
//         ans<--calculation
//          j++;
//     }
//      else if(condition>K){
// while(condition>K){               //we cannot maintain the window here like we used to
//do in fixed sliding window approach, because
//here there is a condition.
//     remove calculation for i
//     i++;
// }
//      j++;
//}
//      return ans;
// }