integer,allocatable::a(:,:)
integer::n(2)
read *,n(1:2)
allocate(a(1:n(1),1:n(2)))
read *,((a(i,j),j=1,n(1)),i=1,n(2))
print *,((a(i,j),j=1,n(1)),i=1,n(2))
deallocate(a)
stop
end
