from django.urls import reverse
from rest_framework import status
from rest_framework.test import APITestCase


class HealthzTests(APITestCase):
    def test_healthz_returns_ok(self):
        response = self.client.get(reverse('healthz'))

        self.assertEqual(response.status_code, status.HTTP_200_OK)
        self.assertEqual(response.json(), {'status': 'ok'})
