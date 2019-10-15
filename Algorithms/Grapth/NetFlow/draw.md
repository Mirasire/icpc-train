
```dot {engine="circo"}
digraph G{
    rankdir=LR;
    s->a [label="1"];
    s->b [label="1"];
    a->b [label="10000"];
    a->t [label="1"];
    b->t [label="1"];
}
```