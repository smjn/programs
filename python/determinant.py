import copy
def minor(matrix,i):
    """Returns the Minor M_0i of matrix"""
    minor = copy.deepcopy(matrix)
    del minor[0] #Delete first row
    for b in list(range(len(matrix))): #Delete column i
        del minor[b][i]
    return minor

def det(A):
    """Recursive function to find determinant"""
    if len(A) == 1: #Base case on which recursion ends
        return A[0][0]
    else:
        determinant = 0
        for x in list(range(len(A))): #Iterates along first row finding cofactors
            print("A:", A)
            determinant += A[0][x] * (-1)**(2+x) * det(minor(A,x)) #Adds successive elements times their cofactors
            print("determinant:", determinant)
        return determinant
