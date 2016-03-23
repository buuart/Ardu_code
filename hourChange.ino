void hourChange(int hr, int minu){
int hrD;
if(hr<10){resByteArray[1]=0;
} else { hrD = hr/10;
resByteArray[1]=clock_set[hrD];
}
int hr0 = hr % 10;
resByteArray[2]=clock_set[hr0];
int miD = minu/10;
resByteArray[3]=clock_set[miD];
int mi0 = minu % 10;
resByteArray[4]=clock_set[mi0];
}