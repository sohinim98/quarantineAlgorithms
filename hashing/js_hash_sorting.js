let unsortedArray = [4, 3, 5, 2];
let hash = [0, 0, 0, 0, 0, 0];

for (elem of unsortedArray) {
  hash[elem]++;
}

for (let i=0; i<hash.length; i++) {
  // considering one instance per element in the sorted array
  // then O(max)
  if(hash[i] >= 1) {
    console.log(i);
  }
}
