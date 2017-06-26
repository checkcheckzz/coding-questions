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

NO_CELEBRITY = {
    'a': ('b', 'c', 'd'),
    'b': ('c', 'd'),
    'c': ('a', 'd'),
    'd': ('e'),
    'e': ('b', 'd'),
}


class _BaseSolution:
    def __init__(self, edges=None):
        self.edges = edges or {}
        self.has_acquaintance_counter = 0
        self.answer = None
        self._called = False

    def HasAcquaintance(self, A, B):
        """Returns True if A knows B."""
        self.has_acquaintance_counter += 1
        return B in self.edges.get(A, ())

    def Solve(self, people=None):
        if people is None:
            people = self.edges.keys()
        celebrity = self.findTheCelebrity(people)
        self.answer = celebrity
        return self.has_acquaintance_counter, self.answer

    def __str__(self):
        if not self._called:
            self.Solve()
        return '%s => %s (%d calls to HasAcquaintance)' % (
            self.__class__.__name__,
            self.answer,
            self.has_acquaintance_counter)

    def findTheCelebrity(self, people):
        """Return the name of the celebrity if they are at the party.

        Return None if there is no celebrity at the party.
        """
        return None


class NSquaredSolution(_BaseSolution):
    """Assume everyone is the celebrity and disqualify them if they can't be
    the celebrity:

    (1) If they know anyone else in the party, they can't be the celebrity.

    (2) If they are not known by everyone else in the party, they also cannot be
        the celebrity.

    If there is an entry remaining in the list of potential celebrities, then
    that is the celebrity.  It's an error if there is more than one potential
    celebrity.
    """
    def findTheCelebrity(self, people):
        import collections
        # each key knows everyone in their matching value
        social_graph = collections.defaultdict(set)

        possible_celebrities = set(people)
        for A in people:
            for B in [p for p in people if p != A]:
                # (1) celebrities don't know anyone at the party
                if self.HasAcquaintance(A, B):
                    social_graph[A].add(B)
                    possible_celebrities.discard(A)
                if self.HasAcquaintance(B, A):
                    social_graph[B].add(A)
                    possible_celebrities.discard(B)

        # (2) celebrities are known by everyone at the party
        for _, celeb in enumerate(possible_celebrities):
            for edges in social_graph.values():
                if celeb not in edges:
                    possible_celebrities.discard(celeb)
                    break

        if possible_celebrities:
            # we assume there's only one celebrity
            return possible_celebrities.pop()

        return None


def main():
    for test_case in (D_IS_THE_CELEBRITY, NO_CELEBRITY):
        print
        print test_case
        print NSquaredSolution(test_case)


if __name__ == '__main__':
    main()
