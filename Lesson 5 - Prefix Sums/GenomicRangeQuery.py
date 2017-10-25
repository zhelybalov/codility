def solution(S, P, Q):
    if not len(S) or not len(P) or len(P) != len(Q):
        return []

    nucleotidesImpact = {key:value for key, value in zip(['A', 'C', 'G', 'T'], range(4))}
    DNA = []
    for nucleotide in S:
        DNA.append(nucleotidesImpact[nucleotide])

    firstFactor = [0] * 4
    firstFactor[DNA[0]] += 1
    factorsAmount = []
    factorsAmount.append(firstFactor)

    for i in range (1, len(DNA)):
        factorsAmount.append(factorsAmount[-1][:])
        factorsAmount[-1][DNA[i]] += 1

    result = [0] * len(P)
    for i in range(len(result)):
        if P[i] > Q[i] or P[i] < 0 or Q[i] >= len(S):
            continue

        left = factorsAmount[P[i] - 1] if (P[i] - 1 >= 0) else [0] * 4
        right = factorsAmount[Q[i]]

        for j in range(len(left)):
            if right[j] > left[j]:
                result[i] = j + 1
                break

    return result


assert [ 0, 0, 0, 1, 2, 4, 1 ] == solution("CAGCCTA", [ -1, 0, 5, 1, 2, 5, 0 ], [ 6, 7, 4, 1, 4, 5, 6 ])
assert [ 2, 1, 2 ] == solution('C' * 1000 + 'A' + 'C' * 1000, [ 0, 0, 1001 ], [ 999, 2000, 2000 ])
