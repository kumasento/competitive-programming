def solution(xs):
    # Your code here
    pos_xs = [x for x in xs if x > 0]
    neg_xs = [x for x in xs if x < 0]
    
    num_negs_to_take = (len(neg_xs) // 2) * 2
    neg_prod = reduce(lambda x, y: x * y, list(sorted(neg_xs))[:num_negs_to_take], 1)
    pos_prod = reduce(lambda x, y: x * y, pos_xs, 1)

    if len(neg_xs) == 1 and len(xs) == 1:
        return neg_xs[0]
    if len(pos_xs) == 0:
        pos_prod = 0
    if len(neg_xs) == 0:
        neg_prod = 0
    if len(neg_xs) == 1:
        neg_prod = neg_xs[0]

    ans = max(pos_prod, neg_prod, pos_prod * neg_prod)
    if len(xs) != len(pos_xs) + len(neg_xs):
        ans = max(0, ans)
    
    return str(ans)
