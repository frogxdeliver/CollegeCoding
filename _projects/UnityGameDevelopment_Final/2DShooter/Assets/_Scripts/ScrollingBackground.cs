using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScrollingBackground : MonoBehaviour
{
    public float scrollSpeed;
    //public float tileSizeZ;

    private Vector3 startPosition;

    // Start is called before the first frame update
    void Start()
    {
        startPosition = transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate((new Vector3(1, 0, 0)) * scrollSpeed * Time.deltaTime);

        if (transform.position.x >= 40)
        {
            transform.position = startPosition;
        }
    }
}
