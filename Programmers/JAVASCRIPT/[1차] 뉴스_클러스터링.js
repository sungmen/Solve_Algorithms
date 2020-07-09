const solution = (str1, str2) => {
  var answer = 0;
  str1 = str1.replace(/[^A-Za-z]/g, ' ');
  str2 = str2.replace(/[^A-Za-z]/g, ' ');
  let str1_ = [], str2_ = [];
  str1=str1.toLowerCase();
  for (let i = 0; i < str1.length - 1; i++) {
      if(str1[i] != ' ' && str1[i+1] != ' ')
          str1_.push(str1[i]+str1[i+1]);
  }
  str1_.sort((a,b) => {return a-b});
  str2=str2.toLowerCase();
  for (let i = 0; i < str2.length - 1; i++) {
      if(str2[i] != ' ' && str2[i+1] != ' ')
          str2_.push(str2[i]+str2[i+1]);
  }
  str2_.sort((a,b) => {return a-b});

  let inter = [];
  let union = [];

  for (var i = 0; i < str2_.length; i++) {
  if (str1_.indexOf(str2_[i]) >= 0) {
    inter.push(str1_.splice(str1_.indexOf(str2_[i]), 1))
  }
  union.push(str2_[i])
}

for (var i = 0; i < str1_.length; i++) {
  union.push(str1_[i])
}

  if (union.length == 0) {
      return 65536
  } 
  if (inter.length ==0 ) {
      return 0;
  }
  return Math.floor(inter.length/union.length*65536);
}