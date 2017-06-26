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


D_IS_THE_CELEBRITY = {
    'a': ('b', 'c', 'd'),
    'b': ('c', 'd'),
    'c': ('a', 'd'),
    'd': (),
    'e': ('b', 'd'),
}


class Solution:
    def __init__(self, edges=None):
        self.edges = edges or {}
        self.has_acquaintance_counter = 0

    def HasAcquaintance(self, A, B):
        """Returns True if A knows B."""
        self.has_acquaintance_counter += 1
        return B in self.edges.get(A, ())

    def __call__(self, people=None):
        if people is None:
            people = self.edges.keys()
        celebrity = self.findTheCelebrity(people)
        return self.has_acquaintance_counter, celebrity

    def findTheCelebrity(self, people):
        """Return the name of the celebrity if they are at the party.

        Return None if there is no celebrity at the party.
        """
        return None


def main():
    s = Solution(D_IS_THE_CELEBRITY)
    print s()


if __name__ == '__main__':
    main()
