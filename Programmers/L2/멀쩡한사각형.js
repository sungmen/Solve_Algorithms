const solution=(w,h)=>{const gcd=(a,b)=>{let c, tmp;if(a<b)b=[a,a=b][0];while(b!=0){c=a%b;a=b;b=c}return a;}
    return w*h-(w+h-gcd(w,h));
}