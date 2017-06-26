# /usr/bin/env python2.7
# vim: set fileencoding=utf-8
"""
In a party of N people, only one person (the celebrity) is known to everyone.
Such a person may be present in the party.  If yes, they don't know anyone else
at the party.

We can only ask whether "does person-A know person-B":

    HasAcquaintance(A, B) returns True if A knows B, False otherwise.

Find the celebrity at the party (if they exist) in as few calls to
HasAcquaintance as possible.
"""


def HasAcquaintance(A, B):
    """d is the celebrity."""
    edges = {
        'a': ('b', 'c', 'd'),
        'b': ('c', 'd'),
        'c': ('a', 'd'),
        'd': (),
        'e': ('b', 'd'),
    }
    return B in edges.get(A, ())


def main():
    pass


if __name__ == '__main__':
    main()
